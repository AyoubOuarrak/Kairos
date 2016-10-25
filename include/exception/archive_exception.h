#ifndef INCLUDE_EXCEPTION_ARCHIVE_EXCEPTION_H
#define INCLUDE_EXCEPTION_ARCHIVE_EXCEPTION_H

#include <kairos_exception.h>
#include <string>

namespace kairos {
namespace exception {

/**
*   Archive exceptions
*/
class ArchiveException : public Exception {
protected:
    /** default constructor without message is not allowed */
    ArchiveException() = default;

    /** assignment operator deleted */
    ArchiveException operator=(const ArchiveException&) = delete;

public:
    /** constructor with char* message */
    explicit ArchiveException(const char* message, const char* info = "");

    /** constructor with std string message */
    explicit ArchiveException(std::string message, std::string info = "");

    /** default distructor */
    ~ArchiveException() = default;

    /** return the exception message */
    const char* what() const throw();
    const char* info() const throw();
};

}
}

#endif