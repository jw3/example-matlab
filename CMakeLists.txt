cmake_minimum_required(VERSION 3.10)
project(example_matlab)

set(CMAKE_CXX_STANDARD 17)
string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--no-undefined")

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
include(matlab)
include(version)
include(BuildInfo)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(NO_OUTPUT_DIRS TARGETS)
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

find_package(PDAL 1.7.0 REQUIRED CONFIG)

include_directories(src)
add_subdirectory(src)
add_subdirectory(ext)

option(WITH_TESTS "enable tests to build" ON)
if (WITH_TESTS)
    enable_testing()
    add_subdirectory(test)
endif ()
