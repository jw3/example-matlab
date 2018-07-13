add_executable(plugin_test driver.cpp MyPluginTest.cpp)
target_link_libraries(plugin_test PRIVATE plugin CONAN_PKG::catch2)

add_matlab_mcr(plugin_test)

add_test(NAME plugin_test
         COMMAND plugin_test)
