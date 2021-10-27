include_directories(../../include/GuiRoot/ ../../include/)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_library(GuiRoot ./GuiRoot.cpp)
target_link_libraries(GuiRoot Threads::Threads)
