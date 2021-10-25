cmake_minimum_required(VERSION 3.21.3)
project(robocar_cpp)

# Define include directory
include_directories(include)

set(THREADS_PREFER_PTHREAD_FLAG ON)

# Package
find_package(Threads REQUIRED)
find_package(Boost 1.76 REQUIRED COMPONENTS json program_options)

add_executable(drive
    src/keyboard_controller.cpp
    src/main.cpp
    )

# Link with -lpthread
target_link_libraries(drive PRIVATE Threads::Threads)

# Link only what is needed from Boost
target_link_libraries(drive PRIVATE Boost::json)
target_link_libraries(drive PRIVATE Boost::program_options)
