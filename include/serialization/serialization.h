#ifndef INCLUDE_SERIALIZATION_SERIALIZATION_H
#define INCLUDE_SERIALIZATION_SERIALIZATION_H

#include "../exception/serialization_exception.h"
#include "serializable.h"
#include <cstdint>
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
    std::ifstream serializationConf;

    /** the Serializer has been initialize?*/
    static bool initialized;

    /** list of serializable objects */
    static std::map<Serializable*, uint16_t> serializableObjects;
    static std::map<Serializable*, std::string> ObjectjFormatSerialization;
    static std::map<uint16_t, std::string> serializedObjectsFiles;

    /** method to init serialization */
    void initSerialization();

protected:
    /** default constructor */
    Serialization();

    /** add obj to the list of object that need to be serialized */
    void registerType(Serializable*);
    void registerType(Serializable*, std::string);

    /** get the serializable object from the id */
    Serializable* getObject(uint16_t id);

    /** type of serialization */
    const static std::string BINARY;
    const static std::string TEXT;

public:
    /** call serialize method for a specific object */
    static void createCheckpoint(Serializable*);

    /** restore object */
    static void restore(Serializable*);

    /** serialize all object in the list */
    void checkpoint();
};

}
}

#endif