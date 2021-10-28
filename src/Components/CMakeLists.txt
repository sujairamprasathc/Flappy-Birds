include_directories(../../include/Components/)

add_library(Building Building.cpp)
add_library(Obstacle Obstacle.cpp)
add_library(Bird Bird.cpp)
add_library(Moon Moon.cpp)
add_library(Stars Stars.cpp)
add_library(ScoreBoard ScoreBoard.cpp)
add_library(PauseElement PauseElement.cpp)
add_library(GameEndBox GameEndBox.cpp)

add_library(ComponentFactory ComponentFactory.cpp)
