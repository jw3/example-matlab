cmake_minimum_required(VERSION 3.0.2)
project(example_matlab_simple)

set(SOURCE_FILES simple.cpp)
add_executable(example_matlab_simple ${SOURCE_FILES})

target_include_directories(example_matlab_simple PUBLIC ${Matlab_INCLUDE_DIRS})
target_link_libraries(example_matlab_simple ${Matlab_ENG_LIBRARY} ${Matlab_MX_LIBRARY})
