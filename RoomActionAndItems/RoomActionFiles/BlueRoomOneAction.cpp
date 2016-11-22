//
// Created by rob on 11/19/16.
//

#include "BlueRoomOneAction.h"

BlueRoomOneAction::BlueRoomOneAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}
BlueRoomOneAction::BlueRoomOneAction(ItemTable *iTable) : AbstractRoomAction(iTable) {}

ActionResults *BlueRoomOneAction::Look() {
    if (commands->getMainItem() == TORCH) {
        itemList->getValue(TORCH)->setLocation(W_ROOM1);
        return new ActionResults(CURRENT, "One of the glass cases appears to be missing a back panel."
                "You think you might be able to get a torch.");
    }
    return AbstractRoomAction::Look();
}

ActionResults * BlueRoomOneAction::Go() {

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(B_ROOM2, "You go north.\n");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(CURRENT, "You can't go back through the door. It's locked. You must find a new way out.\n");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    return new ActionResults(CURRENT,"You can't go there.\n");

}