#include <iostream>
#include "Rooms/Room.h"
#include "Rooms/ThreeKeyRoom.h"
#include "parser.h"
#include "Command.h"
#include "RoomActionAndItems/AbstractRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/ThreeKeyRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/GreenRoomOneAction.h"
#include "Rooms/GreenRoomOne.h"
#include "Graphics/Graphics.h"
AbstractRoomAction *getNewRoomAction(itemLocation location, ItemTable *pTable);
Room *newRoomFactory(itemLocation location, ItemTable *pTable);
void setPlayerLocation(ItemTable *items, ActionResults *actionResults);


int main() {
    //initialize game.
    bool endGame = false;
    ItemTable *items = new ItemTable();
    //   Graphics graphics(0, "keyroom");
    Room    * room = new ThreeKeyRoom("keyroom", items, true);
    parser  * parsingTool = new parser();
    AbstractRoomAction * roomAction;
    Command *command;
    Graphics graphics;
    std::string playerCommand;
    ActionResults *actionResults;
    //int score = 0;


    // Display Game Title animation
    graphics.animation(std::string("GameTitle"));

    // Display beginning text prompt
    graphics.displayText(room->getDescription());
    //std::cout << "Welcome to Private Keys Members Only. Please type" " a command. We are ignoring it.\n";

    roomAction = new ThreeKeyRoomAction(items);
    //std::cout << room->getDescription();

    while(!endGame) {

        //The getText function in graphics will pass a string object
        //getline(cin,playerCommand);

        playerCommand = graphics.getInput();

        if(playerCommand.empty()){
            graphics.displayText(room->getDescription());
            graphics.displayText("No command was entered. You've got to give me something to go on.");
            //std::cout << "No command entered." << endl;
            continue;
        }

        parser *commandObj = new parser;
        command = commandObj->parse(playerCommand);

        roomAction->setCommands(command);
        actionResults = roomAction->Action();

        //Display special effects as required.
        if (actionResults->getSpecialEffect() != NONE) {
            //Quick method that does a switch statement to figure out which special effect to call.
        }

        if (actionResults->getRoom() != CURRENT) {
            //Room has changed, set up a new room and call description of it.
            setPlayerLocation(items, actionResults);
            free(room);
            free(roomAction);
                room   = newRoomFactory(actionResults->getRoom(), items);
            roomAction = getNewRoomAction(actionResults->getRoom(), items);
            //std::cout << room->getDescription() +"\n";
            graphics.displayText(room->getDescription());
            //graphics.setRoom(room->getRoomName());

        } else {

          //room not changed, inform user of status of his action.
            graphics.displayText(actionResults->getReturnDescription());
            //std::cout << actionResults->getReturnDescription() << std::endl;
        }

        free(command);
        free(actionResults);
        free(commandObj);

        /*
         * Here we will have logic to see if end game conditions have been met.
         * */
        endGame = false;
    }
    //game over stuff goes here.

    free(roomAction);
    free(room);
    free(parsingTool);
    return 0;
}

void setPlayerLocation(ItemTable *items, ActionResults *actionResults) { items->getValue(PLAYER)->setLocation(actionResults->getRoom()); }

Room *newRoomFactory(itemLocation location, ItemTable *pTable) {
    switch(location) {
        case G_ROOM1_SIDE1:
        case G_ROOM1_SIDE2:
            return new GreenRoomOne("greenRoomOne", pTable, true);
        case THREE_KEY_ROOM :
            return new ThreeKeyRoom("keyroom",pTable, true);
        default:
            assert(false);
            break;
    }
}

AbstractRoomAction *getNewRoomAction(itemLocation location, ItemTable *iTable) {
    switch(location) {
        case G_ROOM1_SIDE1:
        case G_ROOM1_SIDE2:
            return new GreenRoomOneAction(iTable);
        case THREE_KEY_ROOM :
            return new ThreeKeyRoomAction(iTable);
        default:
            return new ThreeKeyRoomAction(iTable);
    }
    assert(false);
}

