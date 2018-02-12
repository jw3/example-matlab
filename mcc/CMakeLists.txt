add_subdirectory(simple)
add_subdirectory(with-mex)
add_subdirectory(separate-mex)


set(MODULE mcc-example-driver)

add_executable(${MODULE} driver.cpp)
target_include_directories(${MODULE} PRIVATE ${Matlab_INCLUDE_DIRS} ${PDAL_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR}/simple ${CMAKE_CURRENT_BINARY_DIR}/with-mex)
target_link_libraries(${MODULE} PRIVATE ${Matlab_MCR_LIBRARIES} ${PDAL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_CURRENT_BINARY_DIR}/with-mex/libwmex.so)

set_target_properties(${MODULE}
                      PROPERTIES
                      INSTALL_RPATH "${Matlab_MCR_RPATH}"
                      BUILD_WITH_INSTALL_RPATH true)

add_dependencies(${MODULE} libsimplemcc libwmex separate)
