#include "archive_exception.h"

namespace kairos {
namespace exception {

/** 
*   Constructor with char* message 
*/
ArchiveException::ArchiveException(const char* message, const char* info) : Exception(message, info) {
    exp_type = "archive_exception";
}

/**
*   Constructor with std string message
*/
ArchiveException::ArchiveException(std::string message, std::string info) : Exception(message, info) {
    exp_type = "archive_exception";
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
    std::string message = "[INFO EXCEPTION] : " + exp_info;
    return message.c_str();
}

}
}