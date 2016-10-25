#include "serialization_exception.h"
namespace kairos {
namespace exception {

/** 
*   Constructor with char* message 
*/
SerializationException::serialization_exception(char* message, const char* info)
    : Exception(message, info) {
    exp_type = "serialization_exception";
            
}

/** 
*   Constructor with std string message 
*/
SerializationException::serialization_exception(std::string message, std::string info)
    : Exception(message, info) {
    exp_type = "serialization_exception";
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
    std::string message = "[INFO EXCEPTION] : " + exp_info;
    return message.c_str();
}

}
}