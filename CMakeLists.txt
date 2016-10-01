cmake_minimum_required(VERSION 2.8.11)
project(finalAdventureProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp RoomActionAndItems/RoomActionFiles/AbstractRoomAction.cpp RoomActionAndItems/RoomActionFiles/AbstractRoomAction.h RoomActionAndItems/ActionResults.cpp RoomActionAndItems/ActionResults.h RoomActionAndItems/Item.cpp RoomActionAndItems/Item.h RoomActionAndItems/ItemWrapper.cpp RoomActionAndItems/ItemWrapper.h RoomActionAndItems/RoomActionFiles/PodiumRoomAction.cpp RoomActionAndItems/RoomActionFiles/PodiumRoomAction.h RoomActionAndItems/RoomActionFiles/WaterRoomAction.cpp RoomActionAndItems/RoomActionFiles/WaterRoomAction.h)
add_executable(finalAdventureProject ${SOURCE_FILES})

