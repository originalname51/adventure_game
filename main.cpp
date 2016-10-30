#include <iostream>
#include "Rooms/Room.h"
#include "Rooms/ThreeKeyRoom.h"
#include "parser.h"
#include "Command.h"
#include "RoomActionAndItems/AbstractRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/ThreeKeyRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/GreenRoomOneAction.h"

AbstractRoomAction *getNewRoomAction(itemLocation location, ItemTable *pTable);

Room *newRoomFactory(itemLocation location, ItemTable *pTable);

int main() {


    ItemTable *items = new ItemTable();

    std::string KEYROOM = "keyroom";

    Room    * room = new ThreeKeyRoom(KEYROOM, items, true);
    parser  * parsingTool = new parser();

    AbstractRoomAction * roomAction;

    Command * command;

    bool endGame = false;

    std::string playerCommand = "";

    ActionResults *actionResults;
    roomAction = new ThreeKeyRoom(items);
    std::cout << room->getDescription();
    while(!endGame) {

        std::cout << "Please type in command. 'We are ignoring it.'" << std::endl;
        std::cin >> playerCommand;
        command = new Command(GO,WEST);
        roomAction->setCommands(command);
        actionResults = roomAction->Action();
        if (actionResults->getRoom() != CURRENT) {

            items->getValue(PLAYER)->setLocation(actionResults->getRoom());
                room   = newRoomFactory(actionResults->getRoom(), items);
            roomAction = getNewRoomAction(actionResults->getRoom(), items);

        }
        items->getValue(PLAYER)->setLocation(actionResults->getRoom());
            free(command);
            command = new Command(GO,EAST);
            roomAction->setCommands(command);
        std::cout << actionResults->getReturnDescription();
        free(actionResults);
        actionResults = roomAction->Action();
        std::cout << actionResults->getReturnDescription();
        std::cout<< "executing command " + playerCommand;
        endGame = true;
    }



//    std::cout << "Hello";
    free(roomAction);
    free(actionResults);
    free(room);
    free(parsingTool);

}

Room *newRoomFactory(itemLocation location, ItemTable *pTable) {
    switch(location) {
        case G_ROOM1_SIDE1:
        case G_ROOM1_SIDE2:
            //return new ()
        case KEY_ROOM :
            return new ThreeKeyRoom("keyroom",pTable, true);
    }
    assert(false);
}

AbstractRoomAction *getNewRoomAction(itemLocation location, ItemTable *iTable) {
    switch(location) {
        case G_ROOM1_SIDE1:
        case G_ROOM1_SIDE2:
            return new GreenRoomOneAction(iTable);
        case KEY_ROOM :
            return new ThreeKeyRoomAction(iTable);
    }
    assert(true);
}

