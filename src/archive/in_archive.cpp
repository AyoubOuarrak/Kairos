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

/**
*   Second construct of the input archive, it set the stream from parameter
*   param stream input stream
*/
InArchive::InArchive(std::ifstream stream) {
    BasicArchive::inStream = stream;
}

/**
*   Default distruct of the input archive
*/ 
InArchive::~InArchive() {
    BasicArchive::inStream.close();
}

}
}