#ifndef INCLUDE_ARCHIVE_TYPE_VARCHIVE_H
#define VARCHIVE_GUARD

#include "../archive.h"
#include <vector>
#include <string>
#include <fstream>

namespace kairos {
namespace archive {

template <class vector_type>
class VectorArchive : public Archive<std::vector<vector_type> > {
private:
    typedef Archive<std::vector<vector_type> > io_archive;

public:
    VectorArchive() : Archive<std::vector<vector_type> >() {

    }

    VectorArchive& operator<<(const std::vector<vector_type>& item) {
        /*if(io_archive::isInOpen())
            io_archive::closeInStream();

        if(!io_archive::isOutOpen())
            io_archive::openOutStream(std::ios::out | std::ios::app);
*/
        for(int i = 0; i < item.size(); ++i) {
            io_archive::outStream << item[i];
            io_archive::outStream << " ";
        }
        return *this;
    }   

    /**
    *   Overloading operator >> 
    */
    VectorArchive& operator>>(std::vector<vector_type>& item) { 
        if(io_archive::isOutOpen())
            io_archive::closeOutStream();

        if(!io_archive::isInOpen())
            io_archive::openInStream(std::ios::in);

        vector_type el;
        for(; io_archive::inStream >> el; ) 
            item.push_back(el);
        
        return *this;
    }

};


}
}

#endif