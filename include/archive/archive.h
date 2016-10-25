#ifndef ARCHIVE_ARCHIVE_H
#define ARCHIVE_ARCHIVE_H

#include <io_archive.h>

namespace kairos {
namespace archive {

/**
*   High level archive class that save in text and in binary format
*/
class Archive : public IOArchive {
public:
    /** default constructor */
    Archive() : IOArchive("archive") {};
    explicit Archive(std::string name) : IOArchive(name) {};

    /** default copy constructor */
    explicit Archive(const Archive&) = delete;

    /** assignment operator */
    Archive& operator=(const Archive&) = delete;

    /** default distructor */
    virtual ~Archive() = default;
};

}
}
#endif //KAIROS_ARCHIVE_H
