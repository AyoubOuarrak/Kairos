#include <Serialization.h>

namespace kairos {
namespace serialization {

/** constanst initializaton */
const std::string Serialization::BINARY = "binary";
const std::string Serialization::TEXT = "text";

bool Serialization::initialized = false;

std::ifstream Serialization::serializationIndexIn;
std::ofstream Serialization::serializationIndexOut;

std::map<Serializable*, uint16_t>    Serialization::serializableObjects;
std::map<Serializable*, std::string> Serialization::ObjectsFormatSerialization;


/**
*   Default constructor
*/
Serialization::Serialization() {
    if(initialized == false) {
        serializationIndexIn.open("serialization.index", std::ios::in);
        serializationIndexOut.open("serialization.index", std::ios::out);
        initialized = true;
    }
}

/**
*   Default distructor
*/
Serialization::~Serialization() {
    serializationIndexIn.close();
    serializationIndexOut.close();
}


/**
*   Register a new serializable object
*/
void Serialization::registerType(Serializable* obj) {
    uint16_t id = (uint16_t) reinterpret_cast<uint64_t>(obj);
    serializableObjects.insert(std::pair<Serializable*, uint16_t>(obj, id));
    ObjectsFormatSerialization.insert(std::pair<Serializable*, std::string>(obj, Serialization::TEXT));
}

/**
*   Register a new serializable object
*/
void Serialization::registerType(Serializable* obj, std::string type) {
    uint16_t id = (uint16_t) reinterpret_cast<uint64_t>(obj);
    serializableObjects.insert(std::pair<Serializable*, uint16_t>(obj, id));

    if(type == Serialization::TEXT || type == Serialization::BINARY)
        ObjectsFormatSerialization.insert(std::pair<Serializable*, std::string>(obj, type));
    else
        throw SerializationException("wrong serialization type");
}

/**
*   Serialize a specific object
*/
void Serialization::createCheckpoint(Serializable* ser) {
    std::string demangledObject = utils::demangleObject(*ser);
    std::string definedFile = "";
    std::string serializationFormat = "";
    uint16_t id = 0;

    /** call serialize method for ser */
    try {
        id = serializableObjects.at(ser);
        serializationFormat = ObjectsFormatSerialization.at(ser);
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

    } catch (SerializationException* exp) {
        throw exp;
    }

    /** rename the file that contain the serialization */
    if(std::ifstream("archive.text")) {
        definedFile = "archive.text." + demangledObject + "." + std::to_string(id);
        std::rename("archive.text", definedFile.c_str());
    }

    else if(std::ifstream("archive.binary")) {
        definedFile = "archive.binary." + demangledObject + "." + std::to_string(id);
        std::rename("archive.binary", definedFile.c_str());
    }

    /** write the serialization info into the index*/
    serializationIndexOut << demangledObject << " "
                          << serializationFormat << " "
                          << definedFile << "\n";
}

/**
*   Serialize all object that are serializable
*/
void Serialization::checkpoint() {
    for(auto it = serializableObjects.begin(); it != serializableObjects.end(); ++it) {
        std::string serializationFormat = ObjectsFormatSerialization.at((it->first));
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