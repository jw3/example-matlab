cmake_minimum_required(VERSION 3.8)
project(example_matlab)

find_library(Matlab REQUIRED)
find_package(Matlab COMPONENTS MX_LIBRARY ENG_LIBRARY)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory("${PROJECT_SOURCE_DIR}/simple")
