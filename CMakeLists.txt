cmake_minimum_required(VERSION 3.0)

# Set the project name
project(Flappy-Birds)

# Add libraries used
link_libraries(GL GLU glut SDL2 SDL2_ttf SDL2_mixer SDL2_image SDL2_gfx)

# Add include path to all targets and libraries
include_directories(./include/)

add_library(SDL2_Widgets src/CSRP_SDL2_widgets.cpp)
add_library(SDL2_Windows src/CSRP_SDL2_windows.cpp)
add_library(SDL2_Texture src/CSRP_SDL2_texture.cpp)
add_library(SDL2_Engine src/CSRP_SDL2_engine.cpp)

# Executable
add_executable(Flappy-Birds src/main.cpp)
target_link_libraries(Flappy-Birds SDL2_Windows SDL2_Widgets SDL2_Texture SDL2_Engine)