cmake_minimum_required(VERSION 3.13)

project(TinyEngine)

add_library(TinyEngine INTERFACE)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
target_include_directories(${PROJECT_NAME} INTERFACE "${PROJECT_SOURCE_DIR}/src")

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(TinyEngine INTERFACE SDL2::SDL2 SDL2::SDL2main)
find_package(sdl2-image CONFIG REQUIRED)
target_link_libraries(TinyEngine INTERFACE SDL2::SDL2_image)
find_package(sdl2-mixer CONFIG REQUIRED)
target_link_libraries(TinyEngine INTERFACE SDL2::SDL2_mixer)
find_package(sdl2-ttf CONFIG REQUIRED)
target_link_libraries(TinyEngine INTERFACE SDL2::SDL2_ttf)

find_package(GLEW CONFIG REQUIRED)
target_link_libraries(TinyEngine INTERFACE GLEW::GLEW)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(TinyEngine INTERFACE imgui::imgui)

find_package(glm CONFIG REQUIRED)
target_link_libraries(TinyEngine INTERFACE glm)

find_package(Boost REQUIRED COMPONENTS filesystem) 
target_link_libraries(TinyEngine INTERFACE Boost::filesystem)


