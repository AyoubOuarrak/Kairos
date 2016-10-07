#ifndef ARCHIVE_ARCHIVE_H
#define ARCHIVE_ARCHIVE_H

#include <IOArchive.h>

namespace kairos {
namespace archive {

/**
*   High level archive class that save in text and in binary format
*/
class Archive : public IOArchive {
public:
    /** default constructor */
    Archive() : IOArchive() {};
    explicit Archive(std::string name) : IOArchive(name) {};

    /** default copy constructor */
    Archive(const Archive&) {};

    /** default distructor */
    ~Archive() {}
};

}
}
#endif //KAIROS_ARCHIVE_H
