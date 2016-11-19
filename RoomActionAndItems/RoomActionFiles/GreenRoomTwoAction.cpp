//
// Created by rob on 10/30/16.
//

#include "GreenRoomTwoAction.h"

GreenRoomTwoAction::GreenRoomTwoAction(ItemTable * iList) : AbstractRoomAction(iList) {}
GreenRoomTwoAction::GreenRoomTwoAction(ItemTable * iList, Command *commands) : AbstractRoomAction(iList, commands) {}


ActionResults *GreenRoomTwoAction::Go() {

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(CURRENT, "You go north.");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(CURRENT, "You go south.");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You go east.");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "The path is blocked.\n");
    }
    return new ActionResults(CURRENT,"You can't go there.");
}