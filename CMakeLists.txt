cmake_minimum_required(VERSION 2.8.11)

project(finalAdventureProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(RESOURCES_PATH "${PROJECT_SOURCE_DIR}/RoomDescriptions/")

configure_file ("configuration.h.in" "${PROJECT_BINARY_DIR}/configuration.h")

include_directories("${PROJECT_BINARY_DIR}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES main.cpp RoomActionAndItems/AbstractRoomAction.cpp RoomActionAndItems/AbstractRoomAction.h RoomActionAndItems/ActionResults.cpp RoomActionAndItems/ActionResults.h ItemsAndActions/Item.cpp ItemsAndActions/Item.h ItemsAndActions/ItemWrapper.cpp ItemsAndActions/ItemWrapper.h ItemsAndActions/Action.cpp ItemsAndActions/Action.h Command.cpp Command.h ItemsAndActions/ItemTable.cpp ItemsAndActions/ItemTable.h Rooms/Room.cpp Rooms/Room.h Rooms/StartRoom.cpp Rooms/StartRoom.h Rooms/KeyRoom.cpp Rooms/KeyRoom.h RoomActionAndItems/RoomActionFiles/KeyRoomAction.cpp RoomActionAndItems/RoomActionFiles/KeyRoomAction.h Graphics/Graphics.cpp Graphics/Graphics.h Graphics/Menu.cpp Graphics/Menu.h Graphics/Animation.cpp Graphics/Animation.h Graphics/Screen.cpp Graphics/Screen.h parser.cpp parser.h)

add_executable(finalAdventureProject ${SOURCE_FILES})
target_link_libraries(finalAdventureProject ${CURSES_LIBRARIES})

project(ITEM_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES RoomActionAndItems/AbstractRoomAction.cpp RoomActionAndItems/AbstractRoomAction.h RoomActionAndItems/ActionResults.cpp RoomActionAndItems/ActionResults.h ItemsAndActions/Item.cpp ItemsAndActions/Item.h ItemsAndActions/ItemWrapper.cpp ItemsAndActions/ItemWrapper.h ItemsAndActions/Action.cpp ItemsAndActions/Action.h Command.cpp Command.h ItemsAndActions/ItemTable.cpp ItemsAndActions/ItemTable.h ItemsAndActions/ItemTest.cpp ItemsAndActions/ItemTest.h Rooms/Room.cpp Rooms/Room.h)
add_executable(ITEM_TEST ${SOURCE_FILES})