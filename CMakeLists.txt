cmake_minimum_required(VERSION 3.8)
project(example_matlab)

find_library(Matlab REQUIRED)
find_package(Matlab COMPONENTS MX_LIBRARY ENG_LIBRARY)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES driver.cpp)
add_executable(example_matlab ${SOURCE_FILES})

target_include_directories(example_matlab PUBLIC ${Matlab_INCLUDE_DIRS})
target_link_libraries(example_matlab ${Matlab_ENG_LIBRARY} ${Matlab_MX_LIBRARY})
