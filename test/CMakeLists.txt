include(add_test_suite)

find_package(JsonCpp)

# suite 1
add_test_suite(test_suite_1 UtilsTest.cpp)
add_matlab_mcr(test_suite_1)

# suite 2 / with mcc lib
add_test_suite(test_suite_2 MyPluginTest.cpp)
target_link_libraries(test_suite_2 PRIVATE ext)
target_include_directories(test_suite_2 PRIVATE ${CMAKE_SOURCE_DIR}/ext)
add_matlab_mcr(test_suite_2)

# add the mocked mcc lib to suite 2
target_sources(test_suite_2 PRIVATE MockSomeMccLib.cpp)

# suite 3
add_test_suite(test_suite_3 PipelineVectTest.cpp)
target_include_directories(test_suite_3 PRIVATE ${JSONCPP_INCLUDE_DIRS})
