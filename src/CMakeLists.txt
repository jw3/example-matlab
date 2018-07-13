add_library(plugin MyPlugin.h MyPlugin.cpp)
target_link_libraries(plugin PRIVATE ext)
target_include_directories(plugin PRIVATE ${CMAKE_SOURCE_DIR}/ext)

add_matlab_mcr(plugin)
