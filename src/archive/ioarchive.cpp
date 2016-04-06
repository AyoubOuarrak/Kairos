#include "../../include/archive/ioarchive.h"

namespace kairos {
namespace archive {

/**
*   Default constructor 
*/
IOArchive::IOArchive() : input_archive(), output_archive(), archivePath(".") {
 
}

/**
*   copy operator
*/
IOArchive::IOArchive(const IOArchive& archive_) {

} 

/**
*   Second constructor 
*/
IOArchive::IOArchive(const std::string path) : input_archive(path), output_archive() {
    archivePath = path;
}


}
}

