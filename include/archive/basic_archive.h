#ifndef ARCHIVE_BASIC_ARCHIVE_H
#define ARCHIVE_BASIC_ARCHIVE_H

#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Basic Abstract Archive class
*/
template <class item_type>
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

    /** pure overloading of the operator << */
    virtual BasicArchive& operator<<(const item_type& item) = 0;
    /** pure overloading of the operator >> */
    virtual BasicArchive& operator>>(item_type& item) = 0;
};

/**
*   Input Archive class, extend Basic archive
*/
template <class item_type>
class IArchive : public virtual BasicArchive<item_type> {

protected:


public:
    /** default constructor */
    IArchive();
    /** second constructor */
    explicit IArchive(std::ifstream steam);
    /** default distructor */
    virtual ~IArchive();

    /** pure overloading of the operator >> */
    virtual IArchive<item_type>& operator>>(item_type& item) = 0;
};


/**
*   Ouput Archive class, extend Basic archive 
*/
template <class item_type>
class OArchive : public virtual BasicArchive<item_type> {

protected:
    

public:
    /** default constructor */
    OArchive();
    /** second constructor */
    explicit OArchive(std::ofstream stream);
    /** default distructor */
    virtual ~OArchive();

    /** pure overloading of the operator << */
    virtual OArchive<item_type>& operator<<(const item_type& item) = 0;
};

#include "templates/basic_archive.templates.h"
}
}

#endif 

