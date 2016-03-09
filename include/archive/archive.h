#ifndef ARCHIVE_ARCHIVE_H
#define ARCHIVE_ARCHIVE_H

#include "basic_archive.h"
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Archive class, extend input archive and output archive
*/
template <class item_type>
class Archive : public OArchive<item_type>, public IArchive<item_type> {

private:
    typedef OArchive<item_type> output_archive;
    typedef IArchive<item_type> input_archive;
    typedef Basic_Archive<item_type> io_archive;
    
protected:
    /** local path of the archive in filesystem */
    std::string archivePath;

public:
    /** default constructor */
    Archive();
    /** second constructor */
    Archive(std::string path);
    /** default distructor */
    virtual ~Archive();

    /** overloading of the << operator */
    Archive& operator<<(const item_type& item);

    /** overloading of the << operator */
    Archive& operator>>(item_type& item);
};

#include "templates/archive.templates.h"
}
}

#endif