cmake_minimum_required(VERSION 3.10)
project(example_matlab)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
include(matlab)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
add_subdirectory(src)

option(WITH_TESTS "enable tests to build" ON)
if (WITH_TESTS)
    enable_testing()
    add_subdirectory(test)
endif ()
