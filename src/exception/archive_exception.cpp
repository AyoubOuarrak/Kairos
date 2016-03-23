#include "../../include/exception/archive_exception.h"

namespace kairos {
namespace exception {

/** 
*   Constructor with char* message 
*/
ArchiveException::ArchiveException(char* message, char* info) : Exception(message, info) {
    exp_type = "archive";          
}

/** 
*   Constructor with std string message 
*/
ArchiveException::ArchiveException(std::string message, std::string info) : Exception(message, info) {
    exp_type = "archive"; 
}

/**
*   Return the exception message
*/
const char* ArchiveException::what() const throw() {
    std::string message = "[" + exp_type + "] : " + exp_msg;
    return message.c_str();
}

/**
*   Return the exception info
*/
const char* ArchiveException::info() const throw() {
    std::string message = "[INFO] : " + exp_info;
    return message.c_str();
}

}
}