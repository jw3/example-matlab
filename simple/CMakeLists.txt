cmake_minimum_required(VERSION 3.0.2)
project(simple_matlab_example)

set(SOURCE_FILES simple.cpp)
add_executable(example_matlab_simple ${SOURCE_FILES})

target_include_directories(example_matlab_simple PUBLIC ${Matlab_INCLUDE_DIRS})
target_link_libraries(example_matlab_simple ${Matlab_ENG_LIBRARY} ${Matlab_MX_LIBRARY})

install(TARGETS example_matlab_simple DESTINATION simple_matlab_example/bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "jw3")

set(CPACK_PACKAGE_NAME "simple_matlab_example")
set(CPACK_PACKAGE_VERSION "0.1")
set(CPACK_PACKAGE_DESCRIPTION "an example of things")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")

SET(CPACK_COMPONENTS_ALL Libraries ApplicationData)

include(CPack)
