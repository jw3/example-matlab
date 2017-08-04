cmake_minimum_required(VERSION 3.0.2)
project(example_matlab)

set(MATLAB_ADDITIONAL_VERSIONS
     "R2017a=9.2"
     "R2016b=9.1"
     "R2016a=9.0")

set(MATLAB_FIND_DEBUG true)

find_library(Matlab REQUIRED)
find_package(Matlab COMPONENTS MX_LIBRARY ENG_LIBRARY)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory("${PROJECT_SOURCE_DIR}/simple")
