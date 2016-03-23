#ifndef ARCHIVE_TYPES_BINARY_ARCHIVE_H
#define ARCHIVE_TYPES_BINARY_ARCHIVE_H

#include "../archive.h"
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
    virtual void get(char* p, std::size_t sz);
    virtual void put(char* p, std::size_t sz);
};

}
}

#endif