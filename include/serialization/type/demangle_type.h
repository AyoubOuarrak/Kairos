#ifndef INCLUDE_SERIALIZATION_TYPE_DEMANGLE_TYPE_HPP
#define INCLUDE_SERIALIZATION_TYPE_DEMANGLE_TYPE_HPP
#include <string>
#include <typeinfo>

#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>

namespace kairos {
namespace serialization {

/**
*   Demangle types name 
*/
std::string demangle(const char* name) {
    /** some arbitrary value to eliminate the compiler warning */
    int status = -4; 

    /** enable c++11 by passing the flag -std=c++11 to g++ */
    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };

    return (status == 0) ? res.get() : name;
}

#else

/**
*   does nothing if not g++
*/
std::string demangle(const char* name) {
    return name;
}

}
}
#endif

/**
*   Demangle object
*/
template <class T>
std::string demangleObject(const T& t) {
    return demangle(typeid(t).name());
}

}
}
#endif