#include "../../include/serialization/type/vector.h"

namespace kairos {
namespace serialization {

/**
*   Default constructor
*/
Vector::Vector() {
    archive = new TextArchive();
}

/**
*   constructor that take an archive
*/
Vector::Vector(Archive* archive_)  {
    archive = archive_;
}
/**
*   Default dtor
*/
Vector::~Vector() {
    delete archive;
}

/**
*   copy operator
*/
Vector::Vector(const Vector&) {

}

/**
*   Assignment operator overloading
*/
Archive Vector::operator=(const Vector&) {

}

}
}
