#ifndef ARCHIVE_IOARCHIVE_H
#define ARCHIVE_IOARCHIVE_H

#include <output_archive.h>
#include <input_archive.h>
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Archive class, extend input archive and output archive
*/
class  IOArchive : public OutArchive, public InArchive {
protected:
    /** default constructor */
    IOArchive() : InArchive(), OutArchive() {};

    /** second constructor */
    explicit IOArchive(std::string path) : InArchive(path), OutArchive(path) {};

    /** copy operator */
    explicit IOArchive(const IOArchive&) = delete;

    /** assignment operator */
    IOArchive& operator=(const IOArchive&) = delete;

    /** default distructor */
    virtual ~IOArchive() {};

};

}
}

#endif