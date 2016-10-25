#include "basic_archive.h"

namespace kairos {
namespace archive {

/**
*   Default construct of the basic archive, it set the name of the archive
*/
BasicArchive::BasicArchive() :
        archiveName("archive"),
        inMode(std::ios::in),
        outMode(std::ios::out) {

}

/**
*   Second construct of the basic archive, it set the name of the archive from parameter
*   param archiveName archive name
*/
BasicArchive::BasicArchive(std::string _archiveName) :
        archiveName(_archiveName),
        inMode(std::ios::in),
        outMode(std::ios::out) {

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
*  Rename the archive
*/
void BasicArchive::rename(std::string newName) {
    std::rename(archiveName.c_str(), newName.c_str());
    archiveName = newName;
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
    if (!isInOpen()) {
        try {
            inStream.open(archiveName, inMode);
        } catch (...) {
            throw new ArchiveException("can't open input file: " + archiveName);
        }
    }
}

/** 
*   Open the output stream 
*/
void BasicArchive::openOutStream() {
    if (!isOutOpen())
        try {
            outStream.open(archiveName, outMode);
        } catch (...) {
            throw new ArchiveException("can't open output file: " + archiveName);
        }
}

/**
*   Open the input stream with different archive name
*/
void BasicArchive::openInStream(std::string archive_name) {
    try {
        closeInStream();
        inStream.open(archive_name, inMode);
    } catch (...) {
        throw new ArchiveException("can't open input file: " + archiveName);
    }
}

/**
*   Open the output stream
*/
void BasicArchive::openOutStream(std::string archive_name) {
    try {
        closeOutStream();
        outStream.open(archive_name, outMode);
    } catch (...) {
        throw new ArchiveException("can't open output file: " + archiveName);
    }
}

/** 
*   Open the input stream with a different mode 
*/
void BasicArchive::openInStream(std::ios_base::openmode mode) {
    try {
        closeInStream();
        inStream.open(archiveName, mode);
    } catch (...) {
        throw new ArchiveException("can't open input file: " + archiveName);
    }
}

/** 
*   Open the output stream with a different mode 
*/
void BasicArchive::openOutStream(std::ios_base::openmode mode) {
    try {
        closeOutStream();
        outStream.open(archiveName, mode);
    } catch (...) {
        throw new ArchiveException("can't open output file: " + archiveName);
    }
}

/** 
*   Open the input stream with a different mode 
*/
void BasicArchive::openInStream(std::string archive_name, std::ios_base::openmode mode) {
    try {
        closeInStream();
        inStream.open(archive_name, mode);
    } catch (...) {
        throw new ArchiveException("can't open input file: " + archiveName);
    }
}

/** 
*   Open the output stream with a different mode 
*/
void BasicArchive::openOutStream(std::string archive_name, std::ios_base::openmode mode) {
    try {
        closeOutStream();
        outStream.open(archive_name, mode);
    } catch (...) {
        throw new ArchiveException("can't open output file: " + archiveName);
    }
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
