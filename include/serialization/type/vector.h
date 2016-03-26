#ifndef INCLUDE_SERIALIZATION_TYPE_ARCHIVE_H
#define INCLUDE_SERIALIZATION_TYPE_ARCHIVE_H

#include "../../archive/types/text.h"
#include "../../archive/archive.h"
#include <vector>

using namespace kairos::archive;

namespace kairos {
namespace serialization {

/**
*   Serialization of vectors
*/
class Vector {
private:
    Archive* archive;

public:
    /** default constructor */
    Vector();

    /** constructor that take an archive */
    Vector(Archive*);

    /** copy operator */
    Vector(const Vector&);

    /** default dtor */
    virtual ~Vector();
    
    /** assignment operator overloading */
    Archive operator=(const Vector&);

    /** save vector in the archive */
    template <class T>
    void put(const std::vector<T>& src);

    /** get the vector from archive */
    template <class T>
    void get(std::vector<T>& dest);
};

#include "templates/vector.templates.h"

/**
*   << overloding operator
*/
template <class T>
Vector& operator<<(Vector& out, std::vector<T>& item) {
    out.put(item);
    return out;
}

/**
*   >> overloding operator
*/
template <class T>
Vector& operator>>(Vector& in, std::vector<T>& item) {
    in.get(item);
    return in;
}

}
}

#endif