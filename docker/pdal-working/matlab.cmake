#
# Matlab
#
set(MATLAB_FIND_DEBUG TRUE)
set(MATLAB_ADDITIONAL_VERSIONS
        "R2017a=9.2"
        "R2016b=9.1"
        "R2016a=9.0")

find_library(Matlab REQUIRED)
find_package(Matlab COMPONENTS MX_LIBRARY ENG_LIBRARY MAT_LIBRARY REQUIRED)

if(Matlab_FOUND)
    set(CMAKE_REQUIRED_LIBRARIES "${Matlab_LIBRARIES}")
    include_directories(SYSTEM ${Matlab_INCLUDE_DIRS})
    add_definitions(-DHAVE_MATLAB=1)
endif()
