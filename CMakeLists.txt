cmake_minimum_required(VERSION 3.0)

# Set the project name
project(Flappy-Birds)
set(CMAKE_BUILD_TYPE Debug)

# Add libraries used
link_libraries(GL GLU glut SDL2 SDL2_ttf SDL2_mixer SDL2_image SDL2_gfx)

# Compile MVCs
add_subdirectory(src/StartPage/)
add_subdirectory(src/OptionsPage/)
add_subdirectory(src/GamePage/)
add_subdirectory(src/Flappy-Bird/)
add_subdirectory(src/Components/)
add_subdirectory(src/ResultPage/)

# Executable
add_executable(Flappy-Birds src/main.cpp src/AudioEngine.cpp src/model.cpp)
target_link_libraries(Flappy-Birds
  StartPageView StartPageController StartPageModel
  GamePageView GamePageController GamePageModel
  OptionsPageView OptionsPageController OptionsPageModel
  ResultPageView Building Flappy-Bird)
target_include_directories(Flappy-Birds PRIVATE include)
