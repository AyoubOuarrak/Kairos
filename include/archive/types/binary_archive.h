#ifndef ARCHIVE_TYPES_BINARY_ARCHIVE_H
#define ARCHIVE_TYPES_BINARY_ARCHIVE_H

#include "archive.h"
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

class BinaryArchive : public Archive {
private:
public:
    /** default ctor */
    BinaryArchive();

    /** copy constructor */
    BinaryArchive(const BinaryArchive&);

    /** default dtor */
    virtual ~BinaryArchive();

    /** override for binary serialization of sz bytes */
    virtual void get(void* p, std::size_t sz) = 0;
    virtual void put(void* p, std::size_t sz) = 0;
};

}
}

#endif