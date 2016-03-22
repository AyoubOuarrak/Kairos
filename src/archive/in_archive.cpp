#include "../../include/archive/in_archive.h"

namespace kairos {
namespace archive {

/**
*   Default construct of the input archive, it open the input stream
*/
InArchive::InArchive() : BasicArchive() {
    
}

/**
*   copy operator
*/
InArchive::InArchive(const InArchive& i_archive) {

}

}
}