#
# Matlab
#

if (Matlab_ROOT_DIR)
    message(STATUS "======== short circuit MATLAB check [${Matlab_ROOT_DIR}] ========")
    set(Matlab_INCLUDE_DIRS "${Matlab_ROOT_DIR}/extern/include")
else ()
    set(MATLAB_FIND_DEBUG true)
    find_library(Matlab REQUIRED)
    find_package(Matlab COMPONENTS MX_LIBRARY ENG_LIBRARY MAT_LIBRARY REQUIRED)
endif ()

set(MATLAB_LIB_DIR ${Matlab_ROOT_DIR}/bin/glnxa64)
set(Matlab_MCR_RPATH "${Matlab_ROOT_DIR}/runtime/glnxa64" "${MATLAB_LIB_DIR}")
set(Matlab_MCR_LIBRARIES "${Matlab_ROOT_DIR}/runtime/glnxa64/libmwmclmcrrt.so")

set(MATLAB_CPP_LIB_DIR ${Matlab_ROOT_DIR}/extern/bin/glnxa64)
set(Matlab_CPP_LIBRARIES ${MATLAB_CPP_LIB_DIR}/libMatlabEngine.so ${MATLAB_CPP_LIB_DIR}/libMatlabDataArray.so)

function(set_matlab_rpath target)
    set_target_properties(${target} PROPERTIES
                          INSTALL_RPATH "${Matlab_MCR_RPATH}"
                          BUILD_WITH_INSTALL_RPATH true)
endfunction(set_matlab_rpath)
