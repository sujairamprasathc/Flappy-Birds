include_directories(../../include/ResultPage ../../include)
add_library(ResultPageView view.cpp)
target_link_libraries(ResultPageView GameEndBox)
