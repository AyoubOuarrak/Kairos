cmake_minimum_required(VERSION 2.8.9)
project("kairos")
 
include_directories(include/archive)
include_directories(include/archive/templates)
include_directories(include/archive/type)
  
file(GLOB SOURCES "test/*.cpp")
 
add_executable(bin/test ${SOURCES})
