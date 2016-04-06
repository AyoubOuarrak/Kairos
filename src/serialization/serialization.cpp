#include "../../include/serialization/serialization.h"
#include "../../include/archive/types/binary.h"
#include "../../include/archive/types/text.h"
#include "../../include/util.h"
#include <iostream>

namespace kairos {
namespace serialization {

/** constanst initializaton */
const std::string Serialization::BINARY = "binary";
const std::string Serialization::TEXT = "text";

bool Serialization::initialized = false;

std::map<Serializable*, uint16_t>    Serialization::serializableObjects;
std::map<uint16_t, std::string>      Serialization::serializedObjectsFiles;
std::map<Serializable*, std::string> Serialization::ObjectjFormatSerialization;


Serialization::Serialization() {
    if(!Serialization::initialized)
        initSerialization();
}
/**
*   Initialize the serializator
*/
void Serialization::initSerialization() {
    Serialization::initialized = true;

    serializationConf.open("index", std::ios::in);
}

/**
*   Register a new serializable object
*/
void Serialization::registerType(Serializable* obj) {
    uint16_t id = (uint16_t) reinterpret_cast<uint64_t>(obj);
    serializableObjects.insert(std::pair<Serializable*, uint16_t>(obj, id));
    ObjectjFormatSerialization.insert(std::pair<Serializable*, std::string>(obj, Serialization::TEXT));
}

/**
*   Register a new serializable object
*/
void Serialization::registerType(Serializable* obj, std::string type) {
    uint16_t id = (uint16_t) reinterpret_cast<uint64_t>(obj);
    serializableObjects.insert(std::pair<Serializable*, uint16_t>(obj, id));
    if(type == Serialization::TEXT || type == Serialization::BINARY)
        ObjectjFormatSerialization.insert(std::pair<Serializable*, std::string>(obj, type));
    else
        throw SerializationException("wrong serialization type");
}

/**
*   Serialize a specific object
*/
void Serialization::createCheckpoint(Serializable* ser) {
    std::string demangledObject = utils::demangleObject(*ser);
    std::string definedFile = "";
    uint16_t id = 0;

    try {
        id = serializableObjects.at(ser);
        std::string serializationFormat = ObjectjFormatSerialization.at(ser);
        if(serializationFormat == Serialization::TEXT) {
            TextArchive archive;
            ser->serialize(archive);
        }

        if(serializationFormat == Serialization::BINARY) {
            BinaryArchive archive;
            ser->serialize(archive);
        }

    } catch (std::out_of_range exp) {
        throw new SerializationException(demangledObject + " not registered");

    } catch (SerializationException exp) {
        throw exp;
    }

    if(std::ifstream("archive.text")) {
        definedFile = "archive.text." + demangledObject + "." + std::to_string(id);
        std::rename("archive.text", definedFile.c_str());
    }

    else if(std::ifstream("archive.binary")) {
        definedFile = "archive.binary." + demangledObject + "." + std::to_string(id);
        std::rename("archive.binary", definedFile.c_str());
    }

    serializedObjectsFiles.insert(std::pair<uint16_t, std::string>(id, definedFile));
}

/**
*   Restore a serializable object
*/
void Serialization::restore(Serializable* ser) {
    try {
        std::cout << serializableObjects.at(ser) << std::endl;

        //const std::string file = serializedObjectsFiles.at(serializableObjects.at(ser));
       // ser->deserialize(file);
       // std::cout << file << std::endl;

    } catch (std::out_of_range exp) {
        std::cout << exp.what() << std::endl;
        throw new SerializationException("errors trying to deserialize " + utils::demangleObject(*ser));
    }
}

/**
*   Serialize all object that are serializable
*/
void Serialization::checkpoint() {
    for(auto it = serializableObjects.begin(); it != serializableObjects.end(); ++it) {
        std::string serializationFormat = ObjectjFormatSerialization.at((it->first));
        if(serializationFormat == Serialization::TEXT) {
            TextArchive archive;
            (it->first)->serialize(archive);
        }

        if(serializationFormat == Serialization::BINARY) {
            BinaryArchive archive;
            (it->first)->serialize(archive);
        }
    }
}

}
}