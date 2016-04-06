#ifndef ARCHIVE_TYPES_TEXT_ARCHIVE_H
#define ARCHIVE_TYPES_TEXT_ARCHIVE_H

#include "../archive.h"
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

class TextArchive : public Archive {
private:
    /** empty body for binary serialization method */
    void get(char*, std::size_t);
    void put(char*, std::size_t);

public:
    /** default ctor */
    TextArchive();

    /** constructor that take the name of an archive */
    explicit TextArchive(const std::string);

    /** copy constructor */
    TextArchive(const TextArchive&);

    /** assignment operator */
    IOArchive operator=(const TextArchive&);
    
    /** default dtor */
    virtual ~TextArchive();

    /** override for put functions */
    void put(int src);
    void put(long src);
    void put(long long src);
    void put(double src);
    void put(float dest);
    void put(char src);
    void put(bool src);

    /** override for get functions */
    void get(int& dest);
    void get(long& dest);
    void get(long long& dest);
    void get(double& dest);
    void get(float& dest);
    void get(char& dest);
    void get(bool& dest);

};

}
}

#endif