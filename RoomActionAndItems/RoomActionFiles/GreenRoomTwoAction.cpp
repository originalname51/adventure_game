//
// Created by rob on 10/30/16.
//

#include "GreenRoomTwoAction.h"

GreenRoomTwoAction::GreenRoomTwoAction(ItemTable * iList) : AbstractRoomAction(iList) {}
GreenRoomTwoAction::GreenRoomTwoAction(ItemTable * iList, Command *commands) : AbstractRoomAction(iList, commands) {}


ActionResults *GreenRoomTwoAction::Go() {

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(G_ROOM4_KID, "You go north.\n");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(G_ROOM3_BASIN, "You go south.\n");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(G_ROOM1_SIDE2, "You go east.\n");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "Why are you interested in .\n");
    }
    return new ActionResults(CURRENT,"You can't go there.\n");
}