cmake_minimum_required(VERSION 3.0.2)
project(example_matlab)

set(MATLAB_ADDITIONAL_VERSIONS
    "R2017b=9.4"
    "R2017b=9.3"
    "R2017a=9.2"
    "R2016b=9.1"
    "R2016a=9.0")

set(MATLAB_FIND_DEBUG true)

if (NOT Matlab_ROOT_DIR)
    find_library(Matlab REQUIRED)
    find_package(Matlab COMPONENTS MX_LIBRARY ENG_LIBRARY)
else ()
    set(Matlab_INCLUDE_DIRS "${Matlab_ROOT_DIR}/extern/include")
    set(Matlab_MCR_LIBRARIES "${Matlab_ROOT_DIR}/runtime/glnxa64/libmwmclmcrrt.so")
endif ()

message(STATUS "matlab includes: ${Matlab_INCLUDE_DIRS}")
message(STATUS "matlab libraries: ${Matlab_LIBRARIES}")
message(STATUS "matlab mcr libraries: ${Matlab_MCR_LIBRARIES}")

set(CMAKE_CXX_STANDARD 11)

#add_subdirectory("${PROJECT_SOURCE_DIR}/simple")
add_subdirectory(mcc)
