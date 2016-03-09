#ifndef INCLUDE_ARCHIVE_TYPE_VARCHIVE_H
#define INCLUDE_ARCHIVE_TYPE_VARCHIVE_H

#include "../archive.h"
#include <vector>
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Archive compatibility with vectors
*/
template <class type, class vector_type = std::vector<type> >
class VectorArchive : public Archive<type> {
private:
    /** some typedef to write less */
    typedef Archive<type> io_archive;

public:
    /** default constructor */
    VectorArchive();

    /** << operator overloading */
    VectorArchive& operator<<(const vector_type& item);  

    /** Overloading operator >>  */
    VectorArchive& operator>>(vector_type& item);

};

#include "templates/vector.templates.h"
}
}

#endif