#ifndef INCLUDE_ARCHIVE_TYPE_VMATRIX_H
#define INCLUDE_ARCHIVE_TYPE_VMATRIX_H

#include "../archive.h"
#include <vector>
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Archive compatibility with matrix
*/
template <class matrix_type>
class MatrixArchive : public Archive<std::vector<vector_type> > {
private:
    /** some typedef to write less */
    typedef Archive<std::vector<vector_type> > io_archive;

public:
    /** default constructor */
    MatrixArchive();

    /** << operator overloading */
    MatrixArchive& operator<<(const std::vector<vector_type>& item);  

    /** Overloading operator >>  */
    MatrixArchive& operator>>(std::vector<vector_type>& item);

};


}
}

#endif