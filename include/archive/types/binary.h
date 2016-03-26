#ifndef ARCHIVE_TYPES_BINARY_ARCHIVE_H
#define ARCHIVE_TYPES_BINARY_ARCHIVE_H

#include "../archive.h"
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

class BinaryArchive : public Archive {
private:
    /** empty body for text serialization */
    virtual void put(int src);
    virtual void put(long src);
    virtual void put(long long src);
    virtual void put(double src);
    virtual void put(char src);
    virtual void put(bool src);

    virtual void get(int& dest);
    virtual void get(long& dest);
    virtual void get(long long& dest);
    virtual void get(double& dest);
    virtual void get(char& dest);
    virtual void get(bool& dest);

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