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
template <class vector_type, class archive_type = TextArchive>
class Vector : public Archive {
private:

public:
    /** default constructor */
    Vector();

    /** copy operator */
    Vector(const Vector&);

    /** default dtor */
    virtual ~Vector();
    
    /** assignment operator overloading */
    Archive operator=(const Vector&);

    /** save vector in the archive */
    virtual void put(const std::vector<vector_type>& src);

    /** get the vector from archive */
    virtual void get(std::vector<vector_type>& dest);
};

}
}

#endif