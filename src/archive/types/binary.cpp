#include "../../include/archive/types/binary.h"
#include <iostream>
namespace kairos {
namespace archive {

/**
*   Default construct of the text archive
*/
BinaryArchive::BinaryArchive() : Archive() {
    openInStream(std::ios::in | std::ios::binary);
    openOutStream(std::ios::out | std::ios::binary);
    std::rename("archive", "archive.binary");
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


/**
*   Put int in the text archive
*/
void BinaryArchive::put(int) {
    // empty body
}

/**
*   Put long in the text archive
*/
void BinaryArchive::put(long) {
    //empty body
}

/**
*   Put long long in the text archive
*/
void BinaryArchive::put(long long) {
    // empty body
}

/**
*   Put double in the text archive
*/
void BinaryArchive::put(double) {
    // empty body
}

/**
*   Put char in the text archive
*/
void BinaryArchive::put(char) {
    // empty body
}

/**
*   Put bool in the text archive
*/
void BinaryArchive::put(bool) {
    // empty body
}


/**
*   Get int from the archive
*/
void BinaryArchive::get(int&) {
    // empty body
}

/**
*   Get long from the archive
*/
void BinaryArchive::get(long&) {
    // empty body
}

/**
*   Get long long from the archive
*/
void BinaryArchive::get(long long&) {
    // empty body
}

/**
*   Get double from the archive

*/
void BinaryArchive::get(double&) {
    // empty body
}

/**
*   Get bool from the archive
*/
void BinaryArchive::get(bool&) {
    // empty body
}

/**
*   Get bool from the archive
*/
void BinaryArchive::get(char&) {
    // mepty body
}
}
}