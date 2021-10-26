include_directories(../../include/OptionsPage/)

add_library(OptionsPageController ./controller.cpp)
target_link_libraries(OptionsPageController OptionsPageModel OptionsPageView)

add_library(OptionsPageModel ./model.cpp)
target_link_libraries(OptionsPageModel OptionsPageController OptionsPageView)

add_library(OptionsPageView ./view.cpp)
target_link_libraries(OptionsPageView OptionsPageModel OptionsPageController)
