#include "../../include/serialization/serialization.h"

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
void Serialization::createCheckpoint(Serializable& ser) {
    ser.serialize();
}

/**
*   Serialize all object that are serializable
*/
void Serialization::checkpoint() {
    std::map<uint16_t, std::Serializable*>::const_iterator objects;
    for(auto it = objects.begin(); it != objects.end(); ++it) 
        it->serialize();
}

}
}