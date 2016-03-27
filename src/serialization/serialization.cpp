#include "../../include/serialization/type/demangle_type.h"
#include "../../include/serialization/serialization.h"
#include <iostream>

namespace kairos {
namespace serialization {

std::map<Serializable*, uint16_t> Serialization::serializableObjects;
std::map<uint16_t, std::string>   Serialization::serializedObjectsFiles;

/**
*   Register a new serializable object
*/
void Serialization::registerType(Serializable* obj) {
    uint16_t id = (uint16_t) reinterpret_cast<uint64_t>(obj);
    serializableObjects.insert(std::pair<Serializable*, uint16_t>(obj, id));
}

/**
*   Serialize a specific object
*/
void Serialization::createCheckpoint(Serializable* ser) {
    ser->serialize();
    uint16_t id = serializableObjects.at(ser);
    std::string demangledObject = demangleObject(*ser);

    if(std::ifstream("archive.text")) {
        std::string definedFile = "archive.text." + demangledObject + "." + std::to_string(id);
        std::rename("archive.text", definedFile.c_str());
    }

    else if(std::ifstream("archive.binary")) {
        std::string definedFile = "archive.binary." + demangledObject + "." + std::to_string(id);
        std::rename("archive.binary", definedFile.c_str());
    }

    serializedObjectsFiles.insert(std::pair<uint16_t, std::string>(id, demangledObject));
}

/**
*   Serialize all object that are serializable
*/
void Serialization::checkpoint() {
    std::map<uint16_t, Serializable*>::const_iterator objs;
    for(auto it = serializableObjects.begin(); it != serializableObjects.end(); ++it) 
        (it->first)->serialize();
}

}
}