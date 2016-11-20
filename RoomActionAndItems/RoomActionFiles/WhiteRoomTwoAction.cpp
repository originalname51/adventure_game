//
// Created by rob on 11/20/16.
//

#include "WhiteRoomTwoAction.h"

WhiteRoomTwoAction::WhiteRoomTwoAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

WhiteRoomTwoAction::WhiteRoomTwoAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *WhiteRoomTwoAction::Go() {

    std::string information;

    switch(commands->getMainItem()) {
        case LADDER :
            information = "You climb the ladder";
            return new ActionResults(W_ROOM1, information);
        case SOUTH  :
            if (westWallRead && northWallRead && eastWallRead) {
                return new ActionResults(W_ROOM3, "You travel through to the next room");
            } else {
                return new ActionResults(W_ROOM3, "The door is locked but there is no keyhole. You feel you need to do something before it will unlock");
            }
        default :
            return new ActionResults(CURRENT, "You can't go that way");
    }



}

ActionResults *WhiteRoomTwoAction::Use() {
    if(commands->getMainItem() == POWER_CRYSTAL && commands->getActedOnItem() == LIGHT_PILLAR) {
        roomLit = true;
        return new ActionResults(CURRENT, "The light pillar illuminates the room showing interesting descriptions on the "
                "east, west, and north walls. You feel compelled to read each wall, almost as if it is a requirement to "
                "progress down this path.");
    } else {
        return AbstractRoomAction::Use();
    }
}

ActionResults *WhiteRoomTwoAction::Look() {

    std::string information;

    switch(commands->getMainItem()) {

        case EAST_WALL:
            information = "clue 1";
            eastWallRead = true;
            break;
        case WEST_WALL:
            westWallRead = true;
            information = "clue 2";
            break;
        case NORTH_WALL:
            northWallRead = true;
            information = "clue 3";
            break;
        default:
            return AbstractRoomAction::Look();
    }

    if(westWallRead && eastWallRead && northWallRead)
    {
        information += "\n After reading the last clue the room lights up!";
        return new ActionResults(CURRENT,information, FIREWORKS);
    }
    return new ActionResults(CURRENT, information);
}
