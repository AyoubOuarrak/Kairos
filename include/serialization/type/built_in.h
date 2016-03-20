#ifndef INCLUDE_SERIALIZATION_TYPE_BUILT_IN_H
#define INCLUDE_SERIALIZATION_TYPE_BUILT_IN_H

#include "../../archive/types/text.h"
#include "../../archive/archive.h"

namespace kairos {
namespace serialization {

/**
*   Serialization of built-in types
*/
template <class archive_type = TextArchive>
class BuiltIn : public Archive {
private:
public:
    /** default construtor */
    BuiltIn();

    /** copy constructor */
    BuiltIn(const BuiltIn&);

    /** default dtor */
    virtual ~BuiltIn();

    /** assignment operator */
    Archive operator=(const BuiltIn&);

    /** save vector in the archive */
    template <class T>
    void put(const T& src);

    /** get the vector from archive */
    template <class T>
    void get(T& dest);
};

}
}