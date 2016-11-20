cmake_minimum_required(VERSION 2.8.11)

project(finalAdventureProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(RESOURCES_PATH "${PROJECT_SOURCE_DIR}/RoomDescriptions/")

configure_file ("configuration.h.in" "${PROJECT_BINARY_DIR}/configuration.h")

include_directories("${PROJECT_BINARY_DIR}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES main.cpp RoomActionAndItems/AbstractRoomAction.cpp RoomActionAndItems/AbstractRoomAction.h RoomActionAndItems/ActionResults.cpp RoomActionAndItems/ActionResults.h ItemsAndActions/Item.cpp ItemsAndActions/Item.h ItemsAndActions/ItemWrapper.cpp ItemsAndActions/ItemWrapper.h ItemsAndActions/Action.cpp ItemsAndActions/Action.h Command.cpp Command.h ItemsAndActions/ItemTable.cpp ItemsAndActions/ItemTable.h Rooms/Room.cpp Rooms/Room.h Rooms/StartRoom.cpp Rooms/StartRoom.h Rooms/ThreeKeyRoom.cpp Rooms/ThreeKeyRoom.h RoomActionAndItems/RoomActionFiles/GreenRoomOneAction.cpp RoomActionAndItems/RoomActionFiles/GreenRoomOneAction.h Graphics/Graphics.cpp Graphics/Graphics.h Graphics/Menu.cpp Graphics/Menu.h Graphics/Animation.cpp Graphics/Animation.h Graphics/Screen.cpp Graphics/Screen.h parser.cpp parser.h RoomActionAndItems/RoomActionFiles/ThreeKeyRoomAction.cpp RoomActionAndItems/RoomActionFiles/ThreeKeyRoomAction.h Rooms/GreenRoomOne.cpp Rooms/GreenRoomOne.h RoomActionAndItems/RoomActionFiles/GreenRoomTwoAction.cpp RoomActionAndItems/RoomActionFiles/GreenRoomTwoAction.h Rooms/GreenRoomTwo.cpp Rooms/GreenRoomTwo.h Graphics/GameTitle.h Graphics/GameTitle.cpp Graphics/Fireworks.cpp Graphics/Fireworks.h Graphics/AnimationsSubClasses/Firework.cpp Graphics/AnimationsSubClasses/Firework.h RoomActionAndItems/RoomActionFiles/GreenRoomThreeAction.cpp RoomActionAndItems/RoomActionFiles/GreenRoomThreeAction.h Rooms/GreenRoomThree.cpp Rooms/GreenRoomThree.h Rooms/GreenRoomFour.cpp Rooms/GreenRoomFour.h RoomActionAndItems/RoomActionFiles/GreenRoomFourAction.cpp RoomActionAndItems/RoomActionFiles/GreenRoomFourAction.h Rooms/WhiteRoomOne.cpp Rooms/WhiteRoomOne.h RoomActionAndItems/RoomActionFiles/WhiteRoomOneAction.cpp RoomActionAndItems/RoomActionFiles/WhiteRoomOneAction.h Rooms/BlueRoomOne.cpp Rooms/BlueRoomOne.h RoomActionAndItems/RoomActionFiles/BlueRoomOneAction.cpp RoomActionAndItems/RoomActionFiles/BlueRoomOneAction.h Rooms/BlueRoomTwo.cpp Rooms/BlueRoomTwo.h RoomActionAndItems/RoomActionFiles/BlueRoomTwoAction.cpp RoomActionAndItems/RoomActionFiles/BlueRoomTwoAction.h Rooms/BlueRoomThree.cpp Rooms/BlueRoomThree.h RoomActionAndItems/RoomActionFiles/BlueRoomThreeAction.cpp RoomActionAndItems/RoomActionFiles/BlueRoomThreeAction.h RoomActionAndItems/RoomActionFiles/BlueRoomFourAction.cpp RoomActionAndItems/RoomActionFiles/BlueRoomFourAction.h Rooms/BlueRoomFour.cpp Rooms/BlueRoomFour.h RoomActionAndItems/RoomActionFiles/BlueRoomFiveAction.cpp RoomActionAndItems/RoomActionFiles/BlueRoomFiveAction.h Rooms/BlueRoomFive.cpp Rooms/BlueRoomFive.h Rooms/WhiteRoomTwo.cpp Rooms/WhiteRoomTwo.h RoomActionAndItems/RoomActionFiles/WhiteRoomTwoAction.cpp RoomActionAndItems/RoomActionFiles/WhiteRoomTwoAction.h Rooms/WhiteRoomThree.cpp Rooms/WhiteRoomThree.h RoomActionAndItems/RoomActionFiles/WhiteRoomThreeAction.cpp RoomActionAndItems/RoomActionFiles/WhiteRoomThreeAction.h Rooms/WhiteRoomFour.cpp Rooms/WhiteRoomFour.h RoomActionAndItems/RoomActionFiles/WhiteRoomFourAction.cpp RoomActionAndItems/RoomActionFiles/WhiteRoomFourAction.h)

add_executable(finalAdventureProject ${SOURCE_FILES} Graphics/Fireworks.cpp Graphics/Fireworks.h Graphics/AnimationsSubClasses/Firework.cpp Graphics/AnimationsSubClasses/Firework.h)
target_link_libraries(finalAdventureProject ${CURSES_LIBRARIES})

project(ITEM_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES RoomActionAndItems/AbstractRoomAction.cpp RoomActionAndItems/AbstractRoomAction.h RoomActionAndItems/ActionResults.cpp RoomActionAndItems/ActionResults.h ItemsAndActions/Item.cpp ItemsAndActions/Item.h ItemsAndActions/ItemWrapper.cpp ItemsAndActions/ItemWrapper.h ItemsAndActions/Action.cpp ItemsAndActions/Action.h Command.cpp Command.h ItemsAndActions/ItemTable.cpp ItemsAndActions/ItemTable.h ItemsAndActions/ItemTest.cpp ItemsAndActions/ItemTest.h Rooms/Room.cpp Rooms/Room.h)
add_executable(ITEM_TEST ${SOURCE_FILES})