include_directories(../../include/Flappy-Bird/ ../../include/)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_library(Flappy-Bird ./Flappy-Bird.cpp)
target_link_libraries(Flappy-Bird Threads::Threads ComponentFactory ResultPageView)
