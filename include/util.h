#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H

namespace kairos {
namespace utils {

#ifdef __GNUG__

/**
*   Return the name of the type T
*/
template<typename T>
std::string to_string() {
    std::string prettyFunc(__PRETTY_FUNCTION__);
    prettyFunc = prettyFunc.substr(prettyFunc.find("T = ") + 4);
    std::string temp(prettyFunc.begin(),
                     std::find(prettyFunc.begin(), prettyFunc.end(), ']'));
    return temp;
}

#else
#define TO_STRING(x) #x
#endif

}
}

#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>

namespace kairos {
namespace utils {

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

#endif //KAIROS_UTIL_H
