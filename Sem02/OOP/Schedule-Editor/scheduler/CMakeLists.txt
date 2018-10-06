cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(scheduler_all)

# This indicates to CMakeLists in subdirectories that they are part of a larger project
set(COMBINED_PROJECT TRUE)

# Library type
option(STATIC "Set to ON to build scheduler as a static library instead of a shared library" OFF)

#if(TESTS)
#    add_subdirectory(tests)
#endif()

add_subdirectory(source)