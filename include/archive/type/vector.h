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
template <class vector_type>
class VectorArchive : public Archive<std::vector<vector_type> > {
private:
    /** some typedef to write less */
    typedef Archive<std::vector<vector_type> > io_archive;

public:
    /** default constructor */
    VectorArchive();
    /** copy operator */
    VectorArchive(const VectorArchive&);

    Archive<std::vector<vector_type> > operator=(const VectorArchive&);

    /** << operator overloading */
    VectorArchive& operator<<(const std::vector<vector_type>& item);  

    /** Overloading operator >>  */
    VectorArchive& operator>>(std::vector<vector_type>& item);

};

#include "templates/vector.templates.h"
}
}

#endif