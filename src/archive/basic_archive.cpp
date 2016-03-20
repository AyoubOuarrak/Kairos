#include "../../include/archive/basic_archive.h"

namespace kairos {
namespace archive {

/**
*   Default construct of the basic archive, it set the name of the archive
*/
BasicArchive::BasicArchive() : archiveName("archive") {
    inStream.open(archiveName, std::ios::in);
    outStream.open(archiveName, std::ios::out);
}

/**
*   Second construct of the basic archive, it set the name of the archive from parameter
*   param archiveName archive name
*/
BasicArchive::BasicArchive(std::string _archiveName) {
    archiveName = _archiveName;
    inStream.open(archiveName, std::ios::in);
    outStream.open(archiveName, std::ios::out);
}

/**
*   Default distruct of the basic archive
*/ 
BasicArchive::~BasicArchive() {
    inStream.close();
    outStream.close();
}

/**
*   Return the name of the archive
*/
std::string BasicArchive::name() const {
    return archiveName;
}


/**
*   Return if the input stream is open
*/
bool BasicArchive::isInOpen() const {
    return inStream.is_open();
}

/**
*   Return if the output stream is open
*/
bool BasicArchive::isOutOpen() const {
    return outStream.is_open();
}

/** 
*   Open the input stream 
*/
void BasicArchive::openInStream() {
    inStream.open(archiveName, std::ios::in);
}

/** 
*   Open the output stream 
*/
void BasicArchive::openOutStream() {
    outStream.open(archiveName, std::ios::out);
}

/** 
*   Open the input stream with a different mode 
*/
void BasicArchive::openInStream(std::ios_base::openmode mode) {
    inStream.open(archiveName, mode);
}

/** 
*   Open the output stream with a different mode 
*/
void BasicArchive::openOutStream(std::ios_base::openmode mode) {
    outStream.open(archiveName, mode);
}

/** 
*   Open the input stream with a different mode 
*/
void BasicArchive::openInStream(std::string archive_name, 
                                std::ios_base::openmode mode) {
    inStream.open(archive_name, mode);
}

/** 
*   Open the output stream with a different mode 
*/
void BasicArchive::openOutStream(std::string archive_name, 
                                 std::ios_base::openmode mode) {
    outStream.open(archive_name, mode);
}

/** 
*   Close the input stream 
*/
void BasicArchive::closeInStream() {
    inStream.close();
}

/** 
*   Close the input stream 
*/
void BasicArchive::closeOutStream() {
    outStream.close();
}

}
}
