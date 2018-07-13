add_executable(plugin_test driver.cpp MyPluginTest.cpp)
target_link_libraries(plugin_test PRIVATE plugin CONAN_PKG::catch2 ext)
target_include_directories(plugin_test PRIVATE ${CMAKE_SOURCE_DIR}/ext)

# add the mocked mcc lib
target_sources(plugin_test PRIVATE MockSomeMccLib.cpp)

add_matlab_mcr(plugin_test)

add_test(NAME plugin_test
         COMMAND plugin_test)
