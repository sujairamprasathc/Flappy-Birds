add_library(GamePageController ./controller.cpp)
target_link_libraries(GamePageController GamePageModel GamePageView)

add_library(GamePageModel ./model.cpp)
target_link_libraries(GamePageModel GamePageController GamePageView)

add_library(GamePageView ./view.cpp)
target_link_libraries(GamePageView GamePageModel GamePageController Building Bird Obstacle Moon Stars ScoreBoard)
