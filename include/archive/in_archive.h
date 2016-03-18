#ifndef ARCHIVE_INPUT_ARCHIVE_H
#define ARCHIVE_INPUT_ARCHIVE_H

#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Input Archive class, extend Basic archive
*/
class InArchive : protected virtual BasicArchive {
public:
    /** default constructor */
    InArchive();

    /** copy operator */
    InArchive(const IArchive&);
    
    /** second constructor */
    explicit InArchive(std::ifstream steam);
    
    /** default distructor */
    virtual ~InArchive() = default;

    /** pure overloading get operator for scalar types */
    virtual void get(int& dest) = 0;
    virtual void get(long& dest) = 0;
    virtual void get(long long& dest) = 0;
    virtual void get(double& dest) = 0;
    virtual void get(char& dest) = 0;
};

/**
*   >> overloding operator
*/
template <class T>
InArchive& operator>>(InArchive& in, T item) {
    in.get(item);
}

}
}
#endif