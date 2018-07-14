add_library(plugin MyPlugin.h MyPlugin.cpp)
target_link_libraries(plugin PRIVATE ${PDAL_LIBRARIES} ext)
target_include_directories(plugin PRIVATE ${CMAKE_SOURCE_DIR}/ext ${PDAL_INCLUDE_DIRS})

add_matlab_mcr(plugin)
