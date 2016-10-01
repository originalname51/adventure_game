cmake_minimum_required(VERSION 2.8.11)
project(finalAdventureProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp AbstractRoomAction.cpp AbstractRoomAction.h ActionResults.cpp ActionResults.h Item.cpp Item.h ItemWrapper.cpp ItemWrapper.h)
add_executable(finalAdventureProject ${SOURCE_FILES})

