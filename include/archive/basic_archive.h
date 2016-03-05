#ifndef BASIC_ARCHIVE_GUARD
#define BASIC_ARCHIVE_GUARD

#include <string>
#include <fstream>

namespace kairos {
namespace archive {

/**
*   Basic Abstract Archive class
*/
template <class item_type>
class Basic_Archive {

protected:
    /** archive name*/
    std::string _archiveName;

public:
    /** default constructor */
    Basic_Archive();
    /** second constructor */
    explicit Basic_Archive(std::string archive_name);
    /** default distructor */
    virtual ~Basic_Archive();

    /** return the name of the archive */
    std::string name() const;

    /** pure overloading of the operator << */
    virtual Basic_Archive& operator<<(const item_type& item) = 0;
    /** pure overloading of the operator >> */
    virtual Basic_Archive& operator>>(item_type& item) = 0;
};

/**
*   Input Archive class, extend Basic archive
*/
template <class item_type>
class IArchive : public virtual Basic_Archive<item_type> {

protected:
    /** input stream*/
    std::ifstream stream;

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
class OArchive : public virtual Basic_Archive<item_type> {

protected:
    /** input stream*/
    std::ofstream stream;

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

