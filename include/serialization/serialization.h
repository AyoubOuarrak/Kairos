#ifndef INCLUDE_SERIALIZATION_SERIALIZATION_H
#define INCLUDE_SERIALIZATION_SERIALIZATION_H

#include "serializable.h"

namespace kairos {
namespace serialization {

class Serialization {
private:
    /** list of serializable objects */
    std::list<Serializable*> serializableObjects;
    

protected:
    /** iterate through the list and call serialize method */
    void createCheckpoint() const;

    /** add obj to the list of object that need to be serialized */
    void registerType(const Serializable& obj);
};

}
}

#endif