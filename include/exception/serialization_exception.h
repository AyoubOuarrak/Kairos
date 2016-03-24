#ifndef INCLUDE_EXCEPTION_SERIALIZATION_EXCEPTION_H
#define INCLUDE_EXCEPTION_SERIALIZATION_EXCEPTION_H

#include "exception.h"
#include <string>

namespace kairos {
namespace exception {

/**
*   Serialization exceptions
*/
class SerializationException : public Exception {
public:
    /** default constructor without message is not allowed */
    SerializationException() = delete;

    /** assignment operator deleted */
    SerializationException operator=(const SerializationException&) = delete;

    /** constructor with char* message */
    explicit SerializationException(char* message, const char* info = "");

    /** constructor with std string message */
    explicit SerializationException(std::string message, std::string info = "");

    /** default distructor */
    virtual ~SerializationException() = default;

    /** return the exception message */
    virtual const char* what() const throw();
    virtual const char* info() const throw();
};

}
}

#endif