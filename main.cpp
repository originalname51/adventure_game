#include <iostream>
#include "Rooms/Room.h"
#include "Rooms/KeyRoom.h"
#include "parser.h"
#include "Command.h"
#include "RoomActionAndItems/AbstractRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/ThreeKeyRoom.h"

int main() {


    ItemTable *items = new ItemTable();

    std::string KEYROOM = "keyroom";

    Room * room = new KeyRoom(KEYROOM, items, true);
    parser  * parsingTool = new parser();

    AbstractRoomAction * roomAction;

    Command * command;

    bool endGame = false;

    std::string playerCommand = "";

    ActionResults *actionResults;

    while(!endGame) {
        room->getDescription();
        std::cout << "Type in stuff. We are going to pretend you typed in Some form of 'go West'" << std::endl;
        std::cin >> playerCommand;
        command = new Command(GO,WEST);

        roomAction = new ThreeKeyRoom(items,command);

        actionResults = roomAction->Action();
    assert(        actionResults->getRoom() == G_ROOM1_SIDE1);
        std::cout<< "executing command " + playerCommand;
        endGame = true;
    }



//    std::cout << "Hello";
    free(roomAction);
    free(actionResults);
    free(room);
    free(parsingTool);

}