set(libname libsimplemcc)

file(GLOB M_FILES *.m)

message(STATUS "mcc -T link:lib -W cpplib:${libname} ${M_FILES}")

add_custom_command(OUTPUT ${libname}.h ${libname}.so
                   COMMAND mcc
                   ARGS -T link:lib -W cpplib:${libname} ${M_FILES}
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
