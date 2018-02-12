set(name separate)

set(MEX_BIN ${name}.mexa64)
set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB MEX_SOURCE *.c *.cpp)

set(CXXFLAGS ${CXXFLAGS} -std=c++11 -O3 -ffast-math -fPIC)

add_custom_command(OUTPUT ${MEX_BIN}
                   COMMAND mex
                   ARGS ${MEX_SOURCE}
                   DEPENDS ${MEX_SOURCE}
                   COMMENT "Compile ${name} as MEX library")

add_custom_target(${name} ALL
                  DEPENDS ${MEX_BIN}
                  SOURCES ${MEX_SOURCE})

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${MEX_BIN}
        DESTINATION lib)

set(SEPARATE_MEXA64 ${CMAKE_CURRENT_BINARY_DIR}/separate.mexa64 PARENT_SCOPE)
