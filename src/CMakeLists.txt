add_library(plugin Array.h MyPlugin.h MyPlugin.cpp)
target_link_libraries(plugin PRIVATE ${PDAL_LIBRARIES} ext)
target_include_directories(plugin PRIVATE ${CMAKE_SOURCE_DIR}/ext ${PDAL_INCLUDE_DIRS})

add_matlab_mcr(plugin)

add_library(pdal_plugin_filter_VecFilter SHARED VecFilter.hpp VecFilter.cpp)
target_link_libraries(pdal_plugin_filter_VecFilter PRIVATE ${PDAL_LIBRARIES} ext)
target_include_directories(pdal_plugin_filter_VecFilter PRIVATE ${CMAKE_SOURCE_DIR}/ext ${PDAL_INCLUDE_DIRS})

add_matlab_mcr(pdal_plugin_filter_VecFilter)
