#ifndef ARCHIVE_GUARD
#define ARCHIVE_GUARD

#include "basic_archive.h"
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Archive class, extend input archive and output archive
*/

class Archive : public OArchive<int>, public IArchive<int> {

protected:
    /** local path of the archive in filesystem */
    std::string _archivePath;

public:
    /** default constructor */
    Archive();
    /** second constructor */
    Archive(std::string path);
    /** default distructor */
    virtual ~Archive();

    /** overloading of the << operator */
    Archive& operator<<(const int& item);

    /** overloading of the << operator */
    Archive& operator>>(int& item);
};

#include "templates/archive.templates.h"
}
}

#endif