#ifndef ARCHIVE_BASIC_ARCHIVE_H
#define ARCHIVE_BASIC_ARCHIVE_H

#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Basic Archive class
*/
class BasicArchive {
protected:
    /** archive name*/
    std::string archiveName;
    /** input stream*/
    std::ifstream inStream;
    /** input stream*/
    std::ofstream outStream;

public:
    /** default constructor */
    BasicArchive();
    /** second constructor */
    explicit BasicArchive(std::string archive_name);
    /** default distructor */
    virtual ~BasicArchive();


    /** return the name of the archive */
    std::string name() const;

    /** control if the stream is open */
    bool isInOpen() const;
    bool isOutOpen() const;
    /** open the input stream */
    void openInStream();
    void openOutStream();
    /** open the input stream with different mode */
    void openInStream(std::ios_base::openmode);
    void openOutStream(std::ios_base::openmode);
    /** open the input stream with a different mode */
    void openInStream(std::string, std::ios_base::openmode);
    void openOutStream(std::string, std::ios_base::openmode);
    /** close the input stream */
    void closeInStream();
    void closeOutStream();
};

}
}

#endif 