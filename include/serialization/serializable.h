#ifndef INCLUDE_SERIALIZATION_SERIALIZABLE_H
#define INCLUDE_SERIALIZATION_SERIALIZABLE_H

#include "../archive/type/vector.h"
#include "../archive/archive.h"

using namespace kairos::archive;

namespace kairos {
namespace serialization {

/**
*   Abstract class Serializable
*/
class Serializable {
private:

protected:
    /** default constructor */
    Serializable() { };
    /** disable copy constructor */
    Serializable(const Serializable &) = delete;
    /** disable assignment operator */
    Serializable& operator=(const Serializable&) = delete;

    /** default distructor */
    virtual ~Serializable() { };

    /** virtual pure method to serialize native types */
    template <typename T>
    void serialize(Archive<T>&); 

    /** virtual pure method to serialize vector types */
    template <typename T>
    void serialize(VectorArchive<T>&);

    // .... other serialize function for the other types 
};


}
}
#endif