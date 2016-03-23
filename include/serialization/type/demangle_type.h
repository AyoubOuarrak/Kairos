#ifndef INCLUDE_SERIALIZATION_TYPE_DEMANGLE_TYPE_HPP
#define INCLUDE_SERIALIZATION_TYPE_DEMANGLE_TYPE_HPP

#include <string>
#include <typeinfo>

namespace kairos {
namespace serialization {

std::string demangle(const char* name);

template <class T>
std::string demangleObject(const T& t) {
    return demangle(typeid(t).name());
}

}
}
#endif