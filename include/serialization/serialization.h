#ifndef INCLUDE_SERIALIZATION_SERIALIZATION_H
#define INCLUDE_SERIALIZATION_SERIALIZATION_H

#include "../exception/serialization_exception.h"
#include "../archive/types/binary.h"
#include "../archive/types/text.h"
#include "serializable.h"
#include "../utils.h"
#include <iostream>
#include <cstdint>
#include <list>
#include <map>

namespace kairos {
namespace serialization {

using namespace exception;
/**
*   Class Serialization, provide methods for creating checkpoints and reload
*/
class Serialization : public SerializationException {
private:
    /** serialization configuration file */
    static std::ifstream serializationIndexIn;
    static std::ofstream serializationIndexOut;

    static bool initialized;

    /** list of serializable objects */
    static std::map<Serializable*, uint16_t> serializableObjects;
    static std::map<Serializable*, std::string> ObjectsFormatSerialization;

protected:
    /** default constructor */
    Serialization();
    ~Serialization();

    /** add obj to the list of object that need to be serialized */
    static void registerType(Serializable*);
    static void registerType(Serializable*, std::string);

    /** get the serializable object from the id */
    Serializable* getObject(uint16_t id);

    /** type of serialization */
    const static std::string BINARY;
    const static std::string TEXT;

public:
    /** call serialize method for a specific object */
    static void createCheckpoint(Serializable*);

    /** restore object */
    template <class type>
    static std::list<type*> restore();

    /** serialize all object in the list */
    void checkpoint();
};

#include "serialization.template.h"

}
}

#endif