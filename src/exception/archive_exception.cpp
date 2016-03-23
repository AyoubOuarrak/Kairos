#include "../../include/exception/archive_exception.h"

namespace kairos {
namespace exception {

/** 
*   Constructor with char* message 
*/
ArchiveException::ArchiveException(char* message, char* info) 
        : exp_type("archive"), exp_msg(message), exp_info(info) {
            
}

/** 
*   Constructor with std string message 
*/
ArchiveException::ArchiveException(std::string message, std::string) 
        : exp_type("archive"), exp_msg(message), exp_info(info) {
    
}

/**
*   Return the exception message
*/
const char* what() const throw() {
    std::string message = "[" + exp_type + "] : " + exp_msg;
    return message.c_str();
}

/**
*   Return the exception info
*/
const char* info() const throw() {
    std::string message = "[INFO] : " + exp_info;
    return message.c_str();
}

}
}