#ifndef INCLUDE_EXCEPTION_EXCEPTION_H
#define INCLUDE_EXCEPTION_EXCEPTION_H

#include <exception>
#include <string>

namespace kairos {
namespace exception {

/**
*   Abstract class for exceptions
*/
class Exception : public std::exception {
protected:
    /** exception type */
    std::string exp_type;

    /** exception message */
    std::string exp_msg;

    /** string containing additional info about exception */
    std::string exp_info;

public:
    /** default constructor without message is not allowed */
    Exception() = delete;

    /** constructor with char* message */
    explicit Exception(char* message, char* info = "");

    /** constructor with std string message */
    explicit Exception(std::string message, std::string info = "");

    /** default distructor */
    virtual ~Exception() = default;

    /** return the exception message */
    virtual const char* what() const throw() = 0;
    virtual const char* info() const throw() = 0;
};

}
}
#endif
