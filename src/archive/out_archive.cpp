#include "../../include/archive/out_archive.h"

namespace kairos {
namespace archive {

/**
*   Default construct of the output archive, it open the output archive
*/
OArchive::OArchive() : BasicArchive() {

}

/**
*   copy operator 
*/
OArchive::OArchive(const OArchive& o_archive) {
    
} 

/**
*   Second construct of the output archive, it set the output stream from parameter
*   param stream output stream
*/
OArchive::OArchive(std::ofstream stream) {
    BasicArchive::outStream = stream;
}

/**
*   Default output archive distructor
*/ 
OArchive::~OArchive() {
    BasicArchive::outStream.close();
}

}
}