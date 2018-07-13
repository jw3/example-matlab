file(WRITE ${CMAKE_BINARY_DIR}/NAME ${CMAKE_PROJECT_NAME})

configure_file(${CMAKE_SOURCE_DIR}/src/BuildInfo.hpp.in ${CMAKE_BINARY_DIR}/include/BuildInfo.hpp)
include_directories(${CMAKE_BINARY_DIR}/include)
