#ifndef INCLUDE_EXCEPTION_ARCHIVE_EXCEPTION_H
#define INCLUDE_EXCEPTION_ARCHIVE_EXCEPTION_H

#include "exception.h"
#include <string>

namespace kairos {
namespace exception {

/**
*   Archive exceptions
*/
class ArchiveException : public Exception {
public:
    /** default constructor without message is not allowed */
    ArchiveException() = delete;

    /** assignment operator deleted */
    ArchiveException operator=(const ArchiveException&) = delete;

    /** constructor with char* message */
    explicit ArchiveException(char* message, char* info = "");

    /** constructor with std string message */
    explicit ArchiveException(std::string message, std::string info = "");

    /** default distructor */
    virtual ~ArchiveException() = default;

    /** return the exception message */
    virtual const char* what() const throw();
    virtual const char* info() const throw();
};

}
}

#endif