#include <IOArchive.h>

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
IOArchive::IOArchive(std::string path) : input_archive(path) {
    //archivePath = path;
}


}
}

