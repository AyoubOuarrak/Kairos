#ifndef ARCHIVE_ARCHIVE_H
#define ARCHIVE_ARCHIVE_H

#include "out_archive.h"
#include "in_archive.h"

#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Archive class, extend input archive and output archive
*/
class Archive : public OutArchive, public InArchive {
private:
    typedef OutArchive output_archive;
    typedef InArchive input_archive;
    typedef BasicArchive io_archive;
    
protected:
    /** local path of the archive in filesystem */
    std::string archivePath;

public:
    /** default constructor */
    Archive();
    /** copy operator */
    Archive(const Archive&);
    /** second constructor */
    Archive(std::string path);
    /** default distructor */
    virtual ~Archive() = default;

};


}
}

#endif