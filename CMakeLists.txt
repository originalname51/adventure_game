cmake_minimum_required(VERSION 2.8.11)
project(finalAdventureProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp RoomActionAndItems/RoomActionFiles/AbstractRoomAction.cpp RoomActionAndItems/RoomActionFiles/AbstractRoomAction.h ItemsAndActions/ActionResults.cpp ItemsAndActions/ActionResults.h ItemsAndActions/Item.cpp ItemsAndActions/Item.h ItemsAndActions/ItemWrapper.cpp ItemsAndActions/ItemWrapper.h RoomActionAndItems/RoomActionFiles/PodiumRoomAction.cpp RoomActionAndItems/RoomActionFiles/PodiumRoomAction.h RoomActionAndItems/RoomActionFiles/WaterRoomAction.cpp RoomActionAndItems/RoomActionFiles/WaterRoomAction.h ItemsAndActions/Action.cpp ItemsAndActions/Action.h Command.cpp Command.h ItemsAndActions/ItemTable.cpp ItemsAndActions/ItemTable.h)
add_executable(finalAdventureProject ${SOURCE_FILES})

