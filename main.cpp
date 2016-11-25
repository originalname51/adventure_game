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
#include "Rooms/WhiteRoomOne.h"
#include "Rooms/WhiteRoomTwo.h"
#include "Rooms/WhiteRoomThree.h"
#include "Rooms/WhiteRoomFour.h"
#include "Rooms/WhiteRoomFive.h"
#include "RoomActionAndItems/RoomActionFiles/WhiteRoomOneAction.h"
#include "RoomActionAndItems/RoomActionFiles/WhiteRoomTwoAction.h"
#include "RoomActionAndItems/RoomActionFiles/WhiteRoomThreeAction.h"
#include "RoomActionAndItems/RoomActionFiles/WhiteRoomFourAction.h"
#include "RoomActionAndItems/RoomActionFiles/WhiteRoomFiveAction.h"
#include "RoomActionAndItems/RoomActionFiles/GreenRoomTwoAction.h"
#include "RoomActionAndItems/RoomActionFiles/GreenRoomThreeAction.h"
#include "RoomActionAndItems/RoomActionFiles/GreenRoomFourAction.h"
#include "RoomActionAndItems/RoomActionFiles/BlueRoomFiveAction.h"
#include "RoomActionAndItems/RoomActionFiles/BlueRoomFourAction.h"
#include "RoomActionAndItems/RoomActionFiles/BlueRoomThreeAction.h"
#include "RoomActionAndItems/RoomActionFiles/BlueRoomTwoAction.h"
#include "RoomActionAndItems/RoomActionFiles/BlueRoomOneAction.h"
#include "Rooms/GreenRoomTwo.h"
#include "Rooms/GreenRoomThree.h"
#include "Rooms/GreenRoomFour.h"
#include "Rooms/BlueRoomOne.h"
#include "Rooms/BlueRoomTwo.h"
#include "Rooms/BlueRoomThree.h"
#include "Rooms/BlueRoomFour.h"
#include "Rooms/BlueRoomFive.h"


AbstractRoomAction *getNewRoomAction(itemLocation location, ItemTable *pTable);
Room *newRoomFactory(itemLocation location, ItemTable *pTable);
void setPlayerLocation(ItemTable *items, ActionResults *actionResults);
void initializeScreenResizingHandler();


// Graphics graphics(0, std::string(""));

int main() {
    /* DO NOT DELETE THIS SIGNAL HANDLER */
//    initializeScreenResizingHandler();

    //initialize game.
    bool endGame = false;
    ItemTable *items = new ItemTable();
    Room    * room = new ThreeKeyRoom("keyroom", items, true);
    parser  * parsingTool = new parser();
    AbstractRoomAction * roomAction;
    Command *command;
//    Graphics graphics;
    std::string playerCommand;
    ActionResults *actionResults;
    //int score = 0;


    // Display Game Title animation
//    graphics.animation(std::string("GameTitle"));

    // Display beginning text prompt
    std::cout << room->getDescription(false);
//    graphics.setRoom(room->getRoomName());
//    graphics.displayText(room->getDescription());

    roomAction = new ThreeKeyRoomAction(items);

    std::string input;

    while(!endGame) {

        // Get input from the player
        std::getline (std::cin,playerCommand);
//        playerCommand = graphics.getInput();

        if(playerCommand.empty()){
            std::cout << "No Command Entered. You've got to give me something to go on.\n";
  //          graphics.displayText(room->getDescription());
  //          graphics.displayText("No command was entered. You've got to give me something to go on.");
            //std::cout << "No command entered." << endl;
            continue;
        }

        parser *commandObj = new parser;
        command = commandObj->parse(playerCommand);

        if(command->getAction() == NO_ACTION){
            std::cout << "I didn't understand the command\n";
//            graphics.displayText("I didn't understand that command. Type HELP if you need some ideas. Make sure you type each action and item as they appear.");
            continue;
        }

        if(command->getAction() == LOOK && command->getMainItem() == NOTHING){
            std::cout << "Looking around, you see the long form room description.\n";
            //graphics.displayText(room->getDescription());
            continue;
        }

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

         //   graphics.setRoom(room->getRoomName());
         //   graphics.displayText(room->getDescription());
            std::cout<< room->getDescription(false);
        }
        else {
            // Room not changed, inform user of status of his action.
         //   graphics.displayText(actionResults->getReturnDescription());
            std::cout << actionResults->getReturnDescription() << std::endl;
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

//    graphics.animation(std::string("Fireworks"));

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
        case G_ROOM2_BUCKET :
            return new GreenRoomTwo("greenRoomTwo", pTable, true);
        case G_ROOM3_BASIN :
            return new GreenRoomThree("greenRoomThree", pTable, true);
        case G_ROOM4_KID :
            return new GreenRoomFour("greenRoomFour", pTable, true);
        case THREE_KEY_ROOM :
            return new ThreeKeyRoom("keyroom",pTable, true);
        case W_ROOM1 :
            return new WhiteRoomOne("whiteRoomOne", pTable, true);
        case W_ROOM2 :
            return new WhiteRoomTwo("whiteRoomTwo", pTable, true);
        case W_ROOM3 :
            return new WhiteRoomThree("whiteRoomThree", pTable, true);
        case W_ROOM4 :
            return new WhiteRoomFour("whiteRoomFour", pTable, true);
        case W_ROOM5 :
            return new WhiteRoomFive("whiteRoomFinal", pTable, true);
        case B_ROOM1 :
            return new BlueRoomOne("blueRoomOne", pTable, true);
        case B_ROOM2 :
            return new BlueRoomTwo("blueRoomTwo", pTable, true);
        case B_ROOM3 :
            return new BlueRoomThree("blueRoomThree", pTable, true);
        case B_ROOM4 :
            return new BlueRoomFour("blueRoomFour", pTable, true);
        case B_ROOM5 :
            return new BlueRoomFive("blueRoomFinal", pTable, true);
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
        case G_ROOM2_BUCKET:
            return new GreenRoomTwoAction(iTable);
        case G_ROOM3_BASIN :
            return new GreenRoomThreeAction(iTable);
        case G_ROOM4_KID :
            return new GreenRoomFourAction(iTable);
        case THREE_KEY_ROOM :
            return new ThreeKeyRoomAction(iTable);
        case W_ROOM1 :
            return new WhiteRoomOneAction(iTable);
        case W_ROOM2 :
            return new WhiteRoomTwoAction(iTable);
        case W_ROOM3 :
            return new WhiteRoomThreeAction(iTable);
        case W_ROOM4 :
            return new WhiteRoomFourAction(iTable);
        case W_ROOM5 :
            return new WhiteRoomFiveAction(iTable);
        case B_ROOM1 :
            return new BlueRoomOneAction(iTable);
        case B_ROOM2 :
            return new BlueRoomTwoAction(iTable);
        case B_ROOM3 :
            return new BlueRoomThreeAction(iTable);
        case B_ROOM4 :
            return new BlueRoomFourAction(iTable);
        case B_ROOM5 :
            return new BlueRoomFiveAction(iTable);
        default:
            assert(false);
    }
    assert(false);
}

void handle_winch(int sig)
{
    endwin();
    // Needs to be called after an endwin() so ncurses will initialize
    // itself with the new terminal dimensions.
    refresh();

//    graphics.refreshScreen();
}

//  Signal Handling Initialization
void initializeScreenResizingHandler(){
    signal(SIGWINCH, handle_winch);
}


