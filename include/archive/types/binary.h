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
    void put(int src);
    void put(long src);
    void put(long long src);
    void put(double src);
    void put(float dest);
    void put(char src);
    void put(bool src);

    void get(int& dest);
    void get(long& dest);
    void get(long long& dest);
    void get(double& dest);
    void get(float& dest);
    void get(char& dest);
    void get(bool& dest);

public:
    /** default ctor */
    BinaryArchive();

    /** open an input archive */
    explicit BinaryArchive(const std::string);

    /** copy constructor */
    BinaryArchive(const BinaryArchive&);

    /** default dtor */
    virtual ~BinaryArchive();

    /** override for binary serialization of sz bytes */
    void get(char* p, std::size_t sz);
    void put(char* p, std::size_t sz);
};

}
}

#endif