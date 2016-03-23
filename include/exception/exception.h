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
private:
    /** exception message */
    std::string exp;

public:
    /** default constructor without message is not allowed */
    Exception() = delete;

    /** assignment operator deleted */

    /** constructor with char* message */
    explicit Exception(char* message);

    /** constructor with std string message */
    explicit Exception(std::string message);

    /** default distructor */
    virtual ~Exception();

    /** return the exception message */
    virtual const char* what() const throw() = 0;
};

}
}
#endif
