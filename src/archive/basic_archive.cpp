#include "../../include/archive/basic_archive.h"

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
*   Default construct of the input archive, it open the input stream
*/
IArchive::IArchive() : BasicArchive() {
    
}

/**
*   copy operator
*/
IArchive::IArchive(const IArchive& i_archive) {

}

/**
*   Second construct of the input archive, it set the stream from parameter
*   param stream input stream
*/
IArchive::IArchive(std::ifstream stream) {
    BasicArchive::inStream = stream;
}

/**
*   Default distruct of the input archive
*/ 
IArchive::~IArchive() {
    BasicArchive::inStream.close();
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
