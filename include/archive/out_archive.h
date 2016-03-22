#ifndef ARCHIVE_OUTPUT_ARCHIVE_H
#define ARCHIVE_OUTPUT_ARCHIVE_H

#include "basic_archive.h"
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Ouput Archive class, extend Basic archive 
*/
class OutArchive : protected virtual BasicArchive {
public:
    /** default constructor */
    OutArchive();

    /** copy operator */
    OutArchive(const OutArchive&);
    
    /** default distructor */
    virtual ~OutArchive() = default;

    /** pure overloading put operator for scalar types */
    virtual void put(int src) = 0;
    virtual void put(long src) = 0;
    virtual void put(long long src) = 0;
    virtual void put(double src) = 0;
    virtual void put(char src) = 0;
    virtual void put(bool src) = 0;

    /** for binary serialization of sz bytes */
    virtual void put(char* p, std::size_t sz);
};

/**
*   << overloding operator
*/
template <class T>
OutArchive& operator<<(OutArchive& out, T item) {
    out.put(item);
}

}
}

#endif