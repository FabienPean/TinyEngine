cmake_minimum_required(VERSION 3.13)

project(Heightmap)

add_executable(${PROJECT_NAME} main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)

if (NOT TARGET TinyEngine)
	add_subdirectory(../../ "${CMAKE_CURRENT_BINARY_DIR}/TinyEngine")
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE TinyEngine)

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_CURRENT_SOURCE_DIR}/assets
  $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

find_library(NOISE_LIBRARY noise REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${NOISE_LIBRARY})
find_path(NOISE_INCLUDE_DIR noise.h PATH_SUFFIXES noise)
target_include_directories(${PROJECT_NAME} PRIVATE ${NOISE_INCLUDE_DIR})