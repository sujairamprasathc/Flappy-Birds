include_directories(../../include/StartPage/)

add_library(StartPageController ./controller.cpp)
target_link_libraries(StartPageController StartPageModel StartPageView)

add_library(StartPageModel ./model.cpp)
target_link_libraries(StartPageModel StartPageController StartPageView)

add_library(StartPageView ./view.cpp)
target_link_libraries(StartPageView StartPageModel StartPageController)
