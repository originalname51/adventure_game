#include <iostream>
#include <curses.h>
#include <signal.h>
#include <cstring>
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
void initializeScreenResizingHandler();


Graphics graphics(0, std::string(""));

int main() {
    /* DO NOT DELETE THIS SIGNAL HANDLER */
    initializeScreenResizingHandler();

    //initialize game.
    bool endGame = false;
    ItemTable *items = new ItemTable();
    Room    * room = new ThreeKeyRoom("keyroom", items, true);
    parser  * parsingTool = new parser();
    AbstractRoomAction * roomAction;
    Command *command;
    std::string playerCommand = "";
    ActionResults *actionResults;
    //int score = 0;


    // Display Game Title animation
    graphics.animation(std::string("GameTitle"));

    // Display beginning text prompt
    graphics.setRoom(room->getRoomName());
    graphics.displayText(room->getDescription());

    roomAction = new ThreeKeyRoomAction(items);

    while(!endGame) {

        // Get input from the player
        playerCommand = graphics.getInput();
        parser *commandObj = new parser;
        command = commandObj->parse(playerCommand);

        roomAction->setCommands(command);
        actionResults = roomAction->Action();

        //Display special effects as required.
        if (actionResults->getSpecialEffect() != NONE) {
            //Quick method that does a switch statement to figure out which special effect to call.
        }

        if (actionResults->getRoom() != CURRENT) {
            // Room has changed, set up a new room and call description of it.
            setPlayerLocation(items, actionResults);
            free(room);
            free(roomAction);
                room   = newRoomFactory(actionResults->getRoom(), items);
            roomAction = getNewRoomAction(actionResults->getRoom(), items);

            graphics.setRoom(room->getRoomName());
            graphics.displayText(room->getDescription());
        }
        else {
            // Room not changed, inform user of status of his action.
            graphics.displayText(actionResults->getReturnDescription());
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

    graphics.animation(std::string("Fireworks"));

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

void handle_winch(int sig)
{
    endwin();
    // Needs to be called after an endwin() so ncurses will initialize
    // itself with the new terminal dimensions.
    refresh();

    graphics.refreshScreen();
}

//  Signal Handling Initialization
void initializeScreenResizingHandler(){
    signal(SIGWINCH, handle_winch);
}


