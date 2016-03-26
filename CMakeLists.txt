cmake_minimum_required(VERSION 2.8.9)
project("kairos")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


include_directories(include/archive)
include_directories(include/archive/type)
include_directories(include/exception)
include_directories(include/serialization)
include_directories(include/serialization/type)
include_directories(include/serialization/type/templates)
  
file(GLOB SOURCES 
	"test/*.cpp"
	"src/archive/*.cpp"
    "src/archive/types/*.cpp"
    "src/exception/*.cpp"
	"src/serialization/*.cpp"
    "src/serialization/type/*.cpp")

add_executable(bin/test ${SOURCES})
