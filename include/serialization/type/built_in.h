#ifndef INCLUDE_SERIALIZATION_TYPE_BUILT_IN_H
#define INCLUDE_SERIALIZATION_TYPE_BUILT_IN_H

#include "../../archive/types/text.h"
#include "../../archive/archive.h"

namespace kairos {
namespace serialization {

/**
*   Serialization of built-in types
*/
class BuiltIn {
private:
    archive::Archive* archive;

public:
    /** default construtor */
    BuiltIn();

    /** default construtor */
    BuiltIn(archive::Archive*);

    /** copy constructor */
    BuiltIn(const BuiltIn&);

    /** default dtor */
    ~BuiltIn();


    /** save vector in the archive */
    template <class T>
    void put(const T& src);

    /** get the vector from archive */
    template <class T>
    void get(T& dest);
};

#include "templates/built_in.templates.h"

/** 
*   << overloding operator 
*/
template <class T>
BuiltIn& operator<<(BuiltIn& out, const T& item) {
    out.put(item);
}

/** 
*   >> overloding operator 
*/
template <class T>
BuiltIn& operator>>(const BuiltIn& in, T& item) {
    in.get(item);
}

}
}

#endif