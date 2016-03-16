#include "../../../include/serialization/type/vector.h"

/**
*   register the archive type into the archive manager
*/
REGISTER_ARCHIVE(VectorSD);

/**
*   Default constructor
*/
VectorSD::VectorSD() : Archive() {

}

/**
*   copy operator
*/
VectorSD::VectorSD(const VectorSD& varchive) {
    
}

/**
*   Assignment operator overloading
*/
ArchiveSD VectorSD::operator=(const VectorSD& varchive) {

}
