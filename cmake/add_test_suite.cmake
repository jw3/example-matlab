function(add_test_suite name)
    add_executable(${name} ${name}.cpp ${ARGN})
    target_link_libraries(${name} PRIVATE plugin CONAN_PKG::catch2)

    add_test(NAME ${name} COMMAND ${name})
endfunction(add_test_suite)
