//#include "../../../include/archive/types/Binary.h"
#include "../../../include/floating_point.h"
#include <iostream>
#include <Archive.h>
#include <types/Binary.h>

namespace kairos {
namespace archive {

/**
*   Default construct of the text archive
*/
BinaryArchive::BinaryArchive() : Archive() {
    openInStream(std::ios::in | std::ios::binary);
    openOutStream(std::ios::out | std::ios::binary);
    std::rename("archive", "archive.binary");
    Archive::rename("archive.binary");
}

/**
*   Constructor that open an input archive with the given fileName
*/
BinaryArchive::BinaryArchive(const std::string fileName) : Archive(fileName) {

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
*   Put int in the Binary archive
*/
void BinaryArchive::put(int src) {
    put((char*)&src, sizeof(src));
}

/**
*   Put long in the Binary archive
*/
void BinaryArchive::put(long src) {
    put((char*)&src, sizeof(src));
}

/**
*   Put long long in the Binary archive
*/
void BinaryArchive::put(long long src) {
    put((char*)&src, sizeof(src));
}

/**
*   Put double in the Binary archive
*/
void BinaryArchive::put(double src) {
    uint64_t buffer = to_uint64(src);
    put((char*)&buffer, sizeof(src));
}

/**
*   Put float from archive
*/
void BinaryArchive::put(float src) {
    uint32_t buffer =  to_uint32(src);
    put((char*)&buffer, sizeof(src));
}

/**
*   Put char in the Binary archive
*/
void BinaryArchive::put(char src) {
    put((char*)&src, sizeof(src));
}

/**
*   Put string in the Binary archive
*/
void BinaryArchive::put(std::string src) {
    put((char*)&src, sizeof(src));
}

/**
*   Put bool in the Binary archive
*/
void BinaryArchive::put(bool src) {
    put((char*)&src, sizeof(src));
}


/**
*   Get int from the archive
*/
void BinaryArchive::get(int& dst) {
    get((char*)dst, sizeof(dst));
}

/**
*   Get long from the archive
*/
void BinaryArchive::get(long& dst) {
    get((char*)dst, sizeof(dst));
}

/**
*   Get long long from the archive
*/
void BinaryArchive::get(long long& dst) {
    get((char*)dst, sizeof(dst));
}

/**
*   Get double from the archive

*/
void BinaryArchive::get(double& dst) {
    char* buffer;
    get(buffer, sizeof(dst));
    dst = from_uint64((uint64_t)buffer);
}

/**
*   Get float from archive
*/
void BinaryArchive::get(float& dst) {
    char* buffer;
    get(buffer, sizeof(dst));
    dst = from_uint32((uint64_t)buffer);
}

/**
*   Get bool from the archive
*/
void BinaryArchive::get(bool& dst) {
    get((char*)dst, sizeof(dst));
}

/**
*   Get bool from the archive
*/
void BinaryArchive::get(char& dst) {
    get((char*)dst, sizeof(dst));
}

/**
*   Get string from the archive
*/
void BinaryArchive::get(std::string& dst) {
    get((char*)dst.c_str(), sizeof(dst));
}

}
}