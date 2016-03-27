#include "../../include/serialization/type/built_in.h"

namespace kairos {
namespace serialization {

/**
*   Default constructor
*/
BuiltIn::BuiltIn() {
    archive = new archive::TextArchive();
}


/**
*   Take an archive
*/
BuiltIn::BuiltIn(archive::Archive* _archive) {
    archive = _archive;
}

/**
*   Copy constructor
*/
BuiltIn::BuiltIn(const BuiltIn& built_in) {

}

/**
*   Default dtor
*/
BuiltIn::~BuiltIn() {
    delete archive;
}


}
}