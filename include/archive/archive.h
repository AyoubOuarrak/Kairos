#ifndef ARCHIVE_ARCHIVE_H
#define ARCHIVE_ARCHIVE_H

#include "ioarchive.h"

namespace kairos {
namespace archive {

/**
*   High level archive class that save in text and in binary format
*/
class Archive : public IOArchive {
public:
    /** default constructor */
    Archive() : IOArchive() {};
    Archive(const std::string name) : IOArchive(name) {};

    /** default copy constructor */
    Archive(const Archive&) {};

    /** default distructor */
    virtual ~Archive() {}
};

}
}
#endif //KAIROS_ARCHIVE_H
