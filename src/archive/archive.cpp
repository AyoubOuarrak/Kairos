#include "../../include/archive/archive.h"

namespace kairos {
namespace archive {

/**
*   Default constructor 
*/
Archive::Archive() : input_archive(), output_archive(), archivePath(".") {
 
}

/**
*   copy operator
*/
Archive::Archive(const Archive& archive_) {

} 

/**
*   Second constructor 
*/
Archive::Archive(std::string path) : input_archive(), output_archive() {
    archivePath = path;
}


}
}

