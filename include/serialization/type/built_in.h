#ifndef INCLUDE_SERIALIZATION_TYPE_BUILT_IN_H
#define INCLUDE_SERIALIZATION_TYPE_BUILT_IN_H

#include "../../archive/types/text.h"
#include "../../archive/types/binary.h"
#include "../../archive/archive.h"
#include <iostream>

namespace kairos {
namespace serialization {
using archive::Archive;

/**
*   Serialization of built-in types
*/
class BuiltIn {
private:
    Archive* archive;

public:
    /** default construtor */
    BuiltIn();

    /** default construtor */
    BuiltIn(Archive*);

    /** copy constructor */
    BuiltIn(const BuiltIn&);

    /** default dtor */
    ~BuiltIn();


    /** save vector in the archive */
    template <class T>
    void put(T& src);

    /** get the vector from archive */
    template <class T>
    void get(T& dest);
};

#include "templates/built_in.templates.h"

/** 
*   << overloding operator 
*/
template <class T>
BuiltIn& operator<<(BuiltIn& out, T& item) {
    out.put(item);
    return out;
}

/** 
*   >> overloding operator 
*/
template <class T>
BuiltIn& operator>>(BuiltIn& in, T& item) {
    in.get(item);
    return in;
}

}
}

#endif