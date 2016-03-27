#ifndef INCLUDE_SERIALIZATION_SERIALIZABLE_H
#define INCLUDE_SERIALIZATION_SERIALIZABLE_H

#include "../archive/archive.h"

using namespace kairos::archive;

namespace kairos {
namespace serialization {

/**
*   Abstract class Serializable
*/
class Serializable {
private:

public:
    /** default constructor */
    Serializable();
    /** disable copy constructor */
    Serializable(const Serializable &) = delete;
    /** disable assignment operator */
    Serializable& operator=(const Serializable&) = delete;

    /** default distructor */
    virtual ~Serializable();

    /** virtual pure method to serialize types */
    virtual void serialize() = 0;

    /** virtual pure method to deserialize types */
    virtual void deserialize() = 0;
};


}
}
#endif