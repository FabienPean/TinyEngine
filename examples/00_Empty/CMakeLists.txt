cmake_minimum_required(VERSION 3.13)

project(Empty)

add_executable(main main.cpp)

add_subdirectory(../../ "${CMAKE_CURRENT_BINARY_DIR}/TinyEngine")
target_link_libraries(main PRIVATE TinyEngine)
