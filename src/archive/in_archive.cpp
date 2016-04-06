#include "../../include/archive/in_archive.h"

namespace kairos {
namespace archive {

/**
*   Default construct of the input archive, it open the input stream
*/
InArchive::InArchive() : BasicArchive() {
    
}

/**
*    Construct that take the name of an archive
*/
InArchive::InArchive(std::string fileName) : BasicArchive(fileName) {

}

/**
*   copy operator
*/
InArchive::InArchive(const InArchive& i_archive) {

}

}
}