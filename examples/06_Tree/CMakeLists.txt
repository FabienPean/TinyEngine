cmake_minimum_required(VERSION 3.13)

project(Tree)

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