cmake_minimum_required(VERSION 3.0)

# Set the project name
project(Flappy-Birds)
set(CMAKE_BUILD_TYPE Debug)

# Add libraries used
link_libraries(GL GLU glut SDL2 SDL2_ttf SDL2_mixer SDL2_image SDL2_gfx)

add_library(SDL2_Widgets src/CSRP_SDL2_widgets.cpp)
target_include_directories(SDL2_Widgets PUBLIC ./include/)

add_library(SDL2_Windows src/CSRP_SDL2_windows.cpp)
target_include_directories(SDL2_Windows PUBLIC ./include/)

add_library(SDL2_Texture src/CSRP_SDL2_texture.cpp)
target_include_directories(SDL2_Texture PUBLIC ./include/)

add_library(SDL2_Engine src/CSRP_SDL2_engine.cpp)
target_include_directories(SDL2_Engine PUBLIC ./include/)

# Compile MVCs
add_subdirectory(src/StartPage/)
add_subdirectory(src/OptionsPage/)
add_subdirectory(src/GamePage/)
add_subdirectory(src/GuiRoot/)
add_subdirectory(src/GameEngine/)

# Executable
add_executable(Flappy-Birds src/main.cpp src/AudioEngine.cpp)
target_link_libraries(Flappy-Birds SDL2_Windows SDL2_Widgets SDL2_Texture SDL2_Engine
  StartPageView StartPageController StartPageModel
  GamePageView GamePageController GamePageModel
  OptionsPageView OptionsPageController OptionsPageModel
  Building GuiRoot)
