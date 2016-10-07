#include <Exception.h>

namespace kairos {
namespace exception {

/** 
*   Constructor with char* message 
*/
Exception::Exception(char* message, const char* info)
    : exp_type("generic_exception"), exp_msg(message), exp_info(info) {
            
}

/** 
*   Constructor with std string message 
*/
Exception::Exception(std::string message, std::string info) 
    : exp_type("generic_exception"), exp_msg(message), exp_info(info) {
    
}

}
}