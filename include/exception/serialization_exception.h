#ifndef INCLUDE_EXCEPTION_SERIALIZATION_EXCEPTION_H
#define INCLUDE_EXCEPTION_SERIALIZATION_EXCEPTION_H

#include <kairos_exception.h>
#include <string>

namespace kairos {
namespace exception {

/**
*   Serialization exceptions
*/
class SerializationException : public Exception {
protected:
    /** default constructor without message is not allowed */
    SerializationException() = default;

    /** assignment operator deleted */
    SerializationException operator=(const SerializationException&) = delete;

public:
    /** constructor with char* message */
    explicit SerializationException(char* message, const char* info = "");

    /** constructor with std string message */
    explicit SerializationException(std::string message, std::string info = "");

    /** default distructor */
    ~SerializationException() = default;

    /** return the exception message */
    const char* what() const throw();
    const char* info() const throw();
};

}
}

#endif