#ifndef INCLUDE_SERIALIZATION_SERIALIZATION_H
#define INCLUDE_SERIALIZATION_SERIALIZATION_H

#include "serializable.h"
#include <cstdint>

namespace kairos {
namespace serialization {

class Serialization {
private:
    /** list of serializable objects */
    std::map<uint16_t, std::Serializable*> serializableObjects;

protected:
    serialization
    /** call serialize method for a specific object */
    static void createCheckpoint(Serializable&) const;

    /** serialize all object in the list */
    void checkpoint();

    /** add obj to the list of object that need to be serialized */
    uint16_t registerType(const Serializable& obj);
};

}
}

#endif