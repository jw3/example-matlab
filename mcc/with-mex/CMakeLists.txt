set(name with)

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


# ------------------------------------------------------


set(libname libwmex)

file(GLOB M_FILES *.m)

message(STATUS "mcc -T link:lib -W cpplib:${libname} ${MEX_INCLUDES} ${M_FILES}")

add_custom_command(OUTPUT ${libname}.h ${libname}.so
                   COMMAND mcc
                   ARGS ${PSU_INCLUDES} -T link:lib -W cpplib:${libname} ${M_FILES} # with.mexa64 separate.mexa64 #${SEPARATE_MEXA64}
                   DEPENDS ${M_FILES}
                   COMMENT "Compile ${libname} as shared library")

add_custom_target(${libname} ALL
                  DEPENDS ${libname}.h ${libname}.so
                  SOURCES ${M_FILES})

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${libname}.h
        DESTINATION include)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${libname}.so
        DESTINATION lib)

add_dependencies(${libname} with separate)
