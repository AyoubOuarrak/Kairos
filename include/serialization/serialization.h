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
    static std::map<Serializable*, uint16_t> serializableObjects;
    static std::map<uint16_t, std::string> serializedObjectsFiles;

protected:
    /** add obj to the list of object that need to be serialized */
    void registerType(Serializable*);

    /** get the serializable object from the id */
    Serializable* getObject(uint16_t id);

public:
    /** call serialize method for a specific object */
    static void createCheckpoint(Serializable*);

    /** restore object */
    template <class T>
    static void restore();

    /** load the status of a object */
    Serializable* loadCheckpoint();

    /** serialize all object in the list */
    void checkpoint();
};

#include "templates/serialization.templates.h"
}
}

#endif