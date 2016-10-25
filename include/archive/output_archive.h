#ifndef ARCHIVE_OUTPUT_ARCHIVE_H
#define ARCHIVE_OUTPUT_ARCHIVE_H

#include <basic_archive.h>
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Ouput Archive class, extend Basic archive 
*/
class OutArchive : public virtual BasicArchive {
protected:
    /** default constructor */
    OutArchive() : BasicArchive() {};

    explicit OutArchive(std::string name) : BasicArchive(name) {};

    /** copy operator */
    explicit OutArchive(const OutArchive&) = delete;

    /** assignment operator */
    OutArchive& operator=(const OutArchive&) = delete;
    
    /** default distructor */
    virtual ~OutArchive() {};

protected:
    /** pure overloading put operator for scalar types */
    virtual void put(int src) = 0;
    virtual void put(long src) = 0;
    virtual void put(long long src) = 0;
    virtual void put(double src) = 0;
    virtual void put(float dest) = 0;
    virtual void put(char src) = 0;
    virtual void put(bool src) = 0;
    virtual void put(std::string src) = 0;
    /** for binary serialization of sz bytes */
    virtual void put(char* p, std::size_t sz) = 0;

public:
    template <class T>
    friend OutArchive& operator<<(OutArchive& out, T item);
};

/**
*   << overloding operator
*/
template <class T>
OutArchive& operator<<(OutArchive& out, T item) {
    try {
        out.put(item);

    } catch (std::exception exp) {
        out.closeOutStream();
        throw new ArchiveException("Can't put value ", exp.what());
    }
    return out;
}

}
}

#endif