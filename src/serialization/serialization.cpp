#include <serialization.h>

namespace kairos {
namespace serialization {

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
    ObjectsFormatSerialization.insert(std::pair<Serializable*, std::string>(obj, kairos::SerializationFormats::TEXT));
}

/**
*   Register a new serializable object
*/
void Serialization::registerType(Serializable* obj, std::string type) {
    uint16_t id = (uint16_t) reinterpret_cast<uint64_t>(obj);
    serializableObjects.insert(std::pair<Serializable*, uint16_t>(obj, id));

    if(type == kairos::SerializationFormats::TEXT || type == kairos::SerializationFormats::BINARY)
        ObjectsFormatSerialization.insert(std::pair<Serializable*, std::string>(obj, type));
    else
        throw new SerializationException("wrong serialization type");
}

/**
*   Serialize a specific object
*/
void Serialization::createCheckpoint(Serializable* ser) {
    std::string demangledObject = utils::demangleObject(*ser);
    std::string fileName = "";
    std::string serializationFormat = "";
    uint16_t id = 0;

    /** call serialize method for ser */
    try {
        id = serializableObjects.at(ser);
        serializationFormat = ObjectsFormatSerialization.at(ser);

        if(serializationFormat == kairos::SerializationFormats::TEXT) {
            TextArchive archive;

            fileName = "archive.text." + demangledObject + "." + std::to_string(id);
            archive.openOutStream(fileName);

            ser->serialize(archive);
            archive.closeOutStream();

        } else if(serializationFormat == kairos::SerializationFormats::BINARY) {
            BinaryArchive archive;

            fileName = "archive.binary." + demangledObject + "." + std::to_string(id);
            archive.openOutStream(fileName, std::ios::out | std::ios::binary);

            ser->serialize(archive);
            archive.closeOutStream();
        }

    } catch (std::out_of_range exp) {
        throw new SerializationException(demangledObject + " not registered");

    } catch (SerializationException* exp) {
        throw exp;
    }

    /** write the serialization info into the index*/
    serializationIndexOut << demangledObject << " "
                          << serializationFormat << " "
                          << fileName << "\n";
}

/**
*   Serialize all object that are serializable
*/
void Serialization::checkpoint() {
    for(auto it = serializableObjects.begin(); it != serializableObjects.end(); ++it) {
        std::string serializationFormat = ObjectsFormatSerialization.at((it->first));
        if(serializationFormat == kairos::SerializationFormats::TEXT) {
            TextArchive archive;
            (it->first)->serialize(archive);
        }

        if(serializationFormat == kairos::SerializationFormats::BINARY) {
            BinaryArchive archive;
            (it->first)->serialize(archive);
        }
    }
}

}
}