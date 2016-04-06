#ifndef ARCHIVE_IOARCHIVE_H
#define ARCHIVE_IOARCHIVE_H

#include "out_archive.h"
#include "in_archive.h"

#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Archive class, extend input archive and output archive
*/
class  IOArchive : public OutArchive, public InArchive {
private:
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
    IOArchive(const IOArchive&);

    /** second constructor */
    IOArchive(const std::string path);

    /** default distructor */
    virtual ~IOArchive() = default;

};


}
}

#endif