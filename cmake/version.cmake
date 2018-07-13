if (NOT FULL_VERSION_STRING)
    find_package(Git)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} describe --tags --dirty --match "v[0-9]*.[0-9]*.[0-9]*"
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE GIT_DESCRIBE_VERSION
            RESULT_VARIABLE GIT_DESCRIBE_RESULT
            ERROR_VARIABLE GIT_DESCRIBE_ERROR
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    if (GIT_DESCRIBE_RESULT EQUAL 0)
        string(REGEX REPLACE "v([0-9]*)\\.([0-9]*)\\.(.*)" "\\1.\\2.\\3" FULL_VERSION_STRING ${GIT_DESCRIBE_VERSION})
        file(WRITE ${CMAKE_BINARY_DIR}/VERSION ${FULL_VERSION_STRING})
    else ()
        message(FATAL_ERROR "failed to generate version from git describe: ${GIT_DESCRIBE_ERROR}")
    endif ()

    execute_process(
            COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE GIT_COMMIT_ID
            RESULT_VARIABLE GIT_COMMIT_ID_RESULT
            ERROR_VARIABLE GIT_COMMIT_ID_ERROR
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    if (GIT_COMMIT_ID_RESULT EQUAL 0)
        string(SUBSTRING ${GIT_COMMIT_ID} 0 8 GIT_COMMIT_SHORT_ID)
        file(WRITE ${CMAKE_BINARY_DIR}/COMMIT ${GIT_COMMIT_ID})
    else ()
        message(FATAL_ERROR "failed to get commit id: ${GIT_COMMIT_ID_ERROR}")
    endif ()

endif ()

string(REGEX REPLACE "([0-9]*)\\.[0-9]*\\..*" "\\1" VERSION_MAJOR ${FULL_VERSION_STRING})
string(REGEX REPLACE "[0-9]*\\.([0-9]*)\\..*" "\\1" VERSION_MINOR ${FULL_VERSION_STRING})
string(REGEX REPLACE "[0-9]*\\.[0-9]*\\.(.*)" "\\1" VERSION_PATCH ${FULL_VERSION_STRING})

if (NOT ${FULL_VERSION_STRING} STREQUAL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
    message(WARNING "git described version parsing error")
    set(VERSION_PARSING_ERROR 1)
endif ()

message(STATUS "Library Commit: ${GIT_COMMIT_ID}")
message(STATUS "Library Version: ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
