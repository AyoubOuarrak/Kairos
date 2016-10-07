#ifndef ARCHIVE_IOARCHIVE_H
#define ARCHIVE_IOARCHIVE_H

#include <OutputArchive.h>
#include <InputArchive.h>
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Archive class, extend input archive and output archive
*/
class  IOArchive : public OutArchive, public InArchive {
protected:
    typedef OutArchive output_archive;
    typedef InArchive input_archive;
    typedef BasicArchive io_archive;
    
protected:
    /** local path of the archive in filesystem */
    std::string archivePath;

public:
    /** default constructor */
    IOArchive();

    /** copy operator */
    explicit IOArchive(const IOArchive&);

    /** second constructor */
    explicit IOArchive(std::string path);

    /** default distructor */
    virtual ~IOArchive() = default;

};

}
}

#endif