cmake_minimum_required(VERSION 2.8.11)
project(finalAdventureProject)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/Graphics.cpp src/Graphics.h src/Menu.cpp src/Menu.h src/Animation.cpp src/Animation.h src/Screen.cpp src/Screen.h)
add_executable(finalAdventureProject ${SOURCE_FILES})
target_link_libraries(finalAdventureProject ${CURSES_LIBRARIES})

