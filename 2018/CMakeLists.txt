set(MODULE example-2018)

set(CMAKE_CXX_STANDARD 17)

set(MATLAB_CPP_LIB_DIR ${Matlab_ROOT_DIR}/extern/bin/glnxa64)
set(Matlab_CPP_LIBRARIES ${MATLAB_CPP_LIB_DIR}/libMatlabEngine.so ${MATLAB_CPP_LIB_DIR}/libMatlabDataArray.so)


add_executable(${MODULE} driver.cpp)
target_link_libraries(${MODULE} PRIVATE ${Matlab_CPP_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(${MODULE} PRIVATE ${Matlab_INCLUDE_DIRS})
