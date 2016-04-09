#ifndef KAIROS_INCLUDE_UTIL_H
#define KAIROS_INCLUDE_UTIL_H
#include <string>
#include <iostream>
#include <cstring>
#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#endif

namespace kairos {
namespace utils {

/**
*   Check if two template T & U are equal
*/
#define TO_STRING(x) #x

template<typename T>
bool is_same(::std::string U) {
#ifdef __GNUG__
    ::std::string prettyFunc(__PRETTY_FUNCTION__);
    prettyFunc = prettyFunc.substr(prettyFunc.find("T = ") + 4);
    ::std::string temp(prettyFunc.begin(),
                       ::std::find(prettyFunc.begin(), prettyFunc.end(), ']'));
    return temp == U;
#else
    return TO_STRING(T) == U;
#endif
}

/**
*   Demangle types name
*/
inline ::std::string demangle(const char* name) {
#ifdef __GNUG__
    /** some arbitrary value to eliminate the compiler warning */
    int status = -4;

    /** enable c++11 by passing the flag -std=c++11 to g++ */
    ::std::unique_ptr<char, void(*)(void*)> res {
            abi::__cxa_demangle(name, NULL, NULL, &status),
            ::std::free
    };

    return (status == 0) ? res.get() : name;
#else
    return name;
#endif
}


/**
*   Demangle object
*/
template <class T>
::std::string demangleObject(const T& t) {
    return demangle(typeid(t).name());
}

}
}
#endif //KAIROS_UTIL_H
