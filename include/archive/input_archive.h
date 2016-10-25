#ifndef ARCHIVE_INPUT_ARCHIVE_H
#define ARCHIVE_INPUT_ARCHIVE_H

#include <basic_archive.h>
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Input Archive class, extend Basic archive
*/
class InArchive : public virtual BasicArchive {
protected:
    /** default constructor */
    InArchive() : BasicArchive() {};

    /** constructor that take the name of the archive */
    explicit InArchive(std::string name) : BasicArchive(name) {};

    /** copy operator */
    explicit InArchive(const InArchive&) = delete;

    /** assignment operator */
    InArchive& operator=(const InArchive&) = delete;
    
    /** default distructor */
    virtual ~InArchive() {};

protected:
    /** pure overloading get operator for scalar types */
    virtual void get(int& dest) = 0;
    virtual void get(long& dest) = 0;
    virtual void get(long long& dest) = 0;
    virtual void get(double& dest) = 0;
    virtual void get(float& dest) = 0;
    virtual void get(char& dest) = 0;
    virtual void get(bool& dest) = 0;
    virtual void get(std::string& dest) = 0;

    /** for binary serialization of sz bytes */
    virtual void get(char* p, std::size_t sz) = 0;

public:
    template <class T>
    friend InArchive& operator>>(InArchive& in, T& item);
};

/**
*   >> overloding operator
*/
template <class T>
InArchive& operator>>(InArchive& in, T& item) {
    try {
        in.get(item);

    } catch (std::exception e) {
        in.closeInStream();
        throw new ArchiveException("Can't get value ", e.what());
    }
    return in;
}

}
}
#endif