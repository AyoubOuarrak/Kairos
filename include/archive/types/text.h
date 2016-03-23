#ifndef ARCHIVE_TYPES_TEXT_ARCHIVE_H
#define ARCHIVE_TYPES_TEXT_ARCHIVE_H

#include "../archive.h"
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

class TextArchive : public Archive {
private:
public:
    /** default ctor */
    TextArchive();

    /** copy constructor */
    TextArchive(const TextArchive&);

    /** assignment operator */
    Archive operator=(const TextArchive&);
    
    /** default dtor */
    virtual ~TextArchive();

    /** override for put functions */
    virtual void put(int src);
    virtual void put(long src);
    virtual void put(long long src);
    virtual void put(double src);
    virtual void put(char src);
    virtual void put(bool src);

    /** empty body for binary serialization method */
    virtual void put(char*, std::size_t);

    /** override for get functions */
    virtual void get(int& dest);
    virtual void get(long& dest);
    virtual void get(long long& dest);
    virtual void get(double& dest);
    virtual void get(char& dest);
    virtual void get(bool& dest);

    /** empty body for binary serialization method */
    virtual void get(char*, std::size_t);
};

}
}

#endif