#ifndef INCLUDE_SERIALIZATION_TYPE_VARCHIVE_H
#define INCLUDE_SERIALIZATION_TYPE_VARCHIVE_H

#include "../../archive/archive_manager.h"
#include <vector>
#include <string>
#include <fstream>

using namespace kairos::archive;

namespace kairos {
namespace serialization {

/**
*   Archive compatibility with vectors
*/
class VectorSD : public ArchiveManager {
private:

public:
    /** default constructor */
    VectorSD();
    /** copy operator */
    VectorSD(const VectorSD&);

    /** assignment operator overloading */
    ArchiveSD operator=(const VectorSD&);

    /** << operator overloading */
    template <class vector_type>
    void add(const std::vector<vector_type>& vector);  

    /** Overloading operator >>  */
    template <class vector_type>
    std::vector<vector_type> get();

};

#include "templates/vector.templates.h"
}
}

#endif