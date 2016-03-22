#include "../../include/archive/types/binary.h"

namespace kairos {
namespace archive {

/**
*   Default construct of the text archive
*/
BinaryArchive::BinaryArchive() : Archive() {
    openInStream(std::ios::in | std::ios::binary);
    openOutStream(std::ios::out | std::ios::binary);
}

/**
*   Copy operator of text archive
*/
BinaryArchive::BinaryArchive(const BinaryArchive&) {
    
}

/**
*   Default distructor 
*/
BinaryArchive::~BinaryArchive() {

}

/**
*   Read sz bytes from the archive
*/
void BinaryArchive::get(char* p, std::size_t sz) {
    inStream.read(p, sz);
}

/**
*   Write sz bytes to the archive
*/
void BinaryArchive::put(char* p, std::size_t sz) {
    outStream.write(p, sz);
}

}
}