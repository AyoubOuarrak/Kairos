#include "InputArchive.h"

namespace kairos {
namespace archive {

/**
*   Default construct of the input archive, it open the input stream
*/
InArchive::InArchive()  {

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