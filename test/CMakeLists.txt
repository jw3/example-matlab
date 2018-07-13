add_executable(plugin_test MyPluginTest.cpp)

add_test(NAME plugin_test
         COMMAND plugin_test)
