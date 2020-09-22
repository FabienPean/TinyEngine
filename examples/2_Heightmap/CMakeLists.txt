cmake_minimum_required(VERSION 3.13)

project(Heightmap)

add_executable(main main.cpp)
set_target_properties(main PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:main>)

add_subdirectory(../../ "${CMAKE_CURRENT_BINARY_DIR}/TinyEngine")
target_link_libraries(main PRIVATE TinyEngine)

add_custom_command(
  TARGET main POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_CURRENT_SOURCE_DIR}/assets
  $<TARGET_FILE_DIR:main>/assets
)

find_library(NOISE_LIBRARY noise REQUIRED)
target_link_libraries(main PRIVATE ${NOISE_LIBRARY})
find_path(NOISE_INCLUDE_DIR noise.h PATH_SUFFIXES noise)
target_include_directories(main PRIVATE ${NOISE_INCLUDE_DIR})