#include "../../include/serialization/type/demangle_type.h"
#include "../../include/serialization/serialization.h"
#include <cxxabi.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace kairos {
namespace serialization {

/**
*   Register a new serializable object
*/
uint16_t Serialization::registerType(Serializable* obj) {
    uint16_t id = reinterpret_cast<uint64_t>(obj);

    serializableObjects.insert(std::pair<uint16_t, Serializable*>(id, obj));
    return id;
}

/**
*   Serialize a specific object
*/
void Serialization::createCheckpoint(Serializable* ser) {
    ser->serialize();

    uint16_t id = reinterpret_cast<uint64_t>(ser);

    if(std::ifstream("archive.text")) {
        std::string definedFile = "archive.text." + demangleObject(*ser) + "." + std::to_string(id);
        std::rename("archive.text", definedFile.c_str());
    }

    else if(std::ifstream("archive.binary")) {
        std::string definedFile = "archive.binary." + demangleObject(*ser) + "." + std::to_string(id);
        std::rename("archive.binary", definedFile.c_str());
    }
}

/**
*   Serialize all object that are serializable
*/
void Serialization::checkpoint() {
    std::map<uint16_t, Serializable*>::const_iterator objs;
    for(auto it = serializableObjects.begin(); it != serializableObjects.end(); ++it) 
        (it->second)->serialize();
}

}
}