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
class Archive : public OArchive, public IArchive {

private:
    typedef OArchive output_archive;
    typedef IArchive input_archive;
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
    virtual ~Archive();

    /** overloading of the << operator */
    template <clas item_type>
    void add(const item_type& item);

    /** overloading of the << operator */
    template <class item_type>;
    item_type get() const;
};

#include "templates/archive.templates.h"
}
}

#endif