#include "../../../include/serialization/type/built_in.h"

namespace kairos {
namespace serialization {

/**
*   Default constructor
*/
template <class archive_type = TextArchive>
BuiltIn::BuiltIn() {

}

/**
*   Copy constructor
*/
template <class archive_type = TextArchive>
BuiltIn::BuiltIn(const BuiltIn& built_in) {

}

/**
*   Default dtor
*/
template <class archive_type = TextArchive>
BuiltIn::~BuiltIn() {

}

/**
*   Assignment operator
*/
template <class archive_type = TextArchive>
Archive BuiltIn::operator=() {

}

/**
*   Save a built-in type in the vector
*/
template <class T, class archive_type = TextArchive>
void BuiltIn::put(const T& src) {
    archive_type << src;
}

/**
*   Get a built--in type from the vector
*/
template <class T, class archive_type = TextArchive>
void BuiltIn::get(T& src) {
    archive_type >> src;
}

}
}