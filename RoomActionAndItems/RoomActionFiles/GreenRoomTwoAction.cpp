//
// Created by rob on 10/30/16.
//

#include "GreenRoomTwoAction.h"

GreenRoomTwoAction::GreenRoomTwoAction(ItemTable * iList) : AbstractRoomAction(iList) {}
GreenRoomTwoAction::GreenRoomTwoAction(ItemTable * iList, Command *commands) : AbstractRoomAction(iList, commands) {}

ActionResults * GreenRoomTwoAction::Look() {

    if(commands->getMainItem() == BLOOD_BUCKET) {
        return new ActionResults (CURRENT, "The bucket is disgusting, filled with old blood and with a sick smell.");
    }else if(commands->getMainItem() == CHAIR) {
        return new ActionResults (CURRENT, "The chair has been used and is well worn. You notice the bucket next to the chair"
                "has caught the blood of whoever was on it. There is nothing else of importance here.");
    } else {
        return AbstractRoomAction::Look();
    }
}


ActionResults * GreenRoomTwoAction::Pick() {
    if (commands->getMainItem() == CHAIR) {
        return new ActionResults(CURRENT, "There is no way you can carry that chair around.");
    } else {
        return AbstractRoomAction::Pick();
    }
}


ActionResults *GreenRoomTwoAction::Go() {

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(G_ROOM4_KID, "You go north.\n");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(G_ROOM3_BASIN, "You go south.\n");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(G_ROOM1_SIDE2, "You go back to the boat room.\n");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "There is a wall, you can't go that way.\n");
    }
    return new ActionResults(CURRENT,"You can't go there.\n");
}