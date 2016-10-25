#ifndef KAIROS_CONSTANTS_H
#define KAIROS_CONSTANTS_H
#include <string>

namespace kairos {

/**
*   Serialization Formats
*/
class SerializationFormats {
private:
    SerializationFormats() = delete;

public:
    static const std::string TEXT;
    static const std::string BINARY;
    static const std::string JSON;
    static const std::string XML;
};

}
#endif //KAIROS_CONSTANTS_H
