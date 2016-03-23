#include "../../include/exception/serialization_exception.h"

namespace kairos {
namespace exception {

/** 
*   Constructor with char* message 
*/
SerializationException::SerializationException(char* message, char* info) 
    : Exception(message, info) {
    exp_type = "serialization"; 
            
}

/** 
*   Constructor with std string message 
*/
SerializationException::SerializationException(std::string message, std::string) 
    : Exception(message, info) {
    exp_type = "serialization"; 
}

/**
*   Return the exception message
*/
const char* SerializationException::what() const throw() {
    std::string message = "[" + exp_type + "] : " + exp_msg;
    return message.c_str();
}

/**
*   Return the exception info
*/
const char* SerializationException::info() const throw() {
    std::string message = "[INFO] : " + exp_info;
    return message.c_str();
}

}
}