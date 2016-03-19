#ifndef ARCHIVE_OUTPUT_ARCHIVE_H
#define ARCHIVE_OUTPUT_ARCHIVE_H

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
    OutArchive(const OArchive&);

    /** second constructor */
    explicit OutArchive(std::ofstream stream);
    
    /** default distructor */
    virtual ~OutArchive();

    /** pure overloading put operator for scalar types */
    virtual void put(int src) = 0;
    virtual void put(long src) = 0;
    virtual void put(long long src) = 0;
    virtual void put(double src) = 0;
    virtual void put(char src) = 0;
    virtual void put(bool& src) = 0;

    /** for binary serialization of sz bytes */
    virtual void put(void* p, std::size_t sz) = 0;
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