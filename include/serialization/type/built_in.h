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
    Archive* archive;
public:
    /** default construtor */
    BuiltIn();

    /** default construtor */
    BuiltIn(Archive*);

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

    /** << overloding operator */
    template <class T>
    BuiltIn& operator<<(const T& item);

    /** >> overloding operator */
    template <class T>
    BuiltIn& operator>>(T& item);
};

#include "templates/built_in.templates.h"
}
}

#endif