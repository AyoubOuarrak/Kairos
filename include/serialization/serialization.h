#ifndef INCLUDE_SERIALIZATION_SERIALIZATION_H
#define INCLUDE_SERIALIZATION_SERIALIZATION_H

#include "serializable.h"
#include <cstdint>
#include <map>

namespace kairos {
namespace serialization {

/**
*   Class Serialization, provide methods for creating checkpoints and reload
*/
class Serialization {
private:
    /** list of serializable objects */
    std::map<uint16_t, Serializable*> serializableObjects;

protected:
    /** add obj to the list of object that need to be serialized */
    uint16_t registerType(Serializable*);

    /** get the serializable object from the id */
    Serializable* getObject(uint16_t id);

public:
    /** call serialize method for a specific object */
    static void createCheckpoint(Serializable*);

    /** load the status of a object */
    Serializable* loadCheckpoint();

    /** serialize all object in the list */
    void checkpoint();
};

}
}

#endif