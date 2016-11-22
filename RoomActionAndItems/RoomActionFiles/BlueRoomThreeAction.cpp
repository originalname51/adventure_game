//
// Created by rob on 11/19/16.
//

#include "BlueRoomThreeAction.h"

BlueRoomThreeAction::BlueRoomThreeAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}

BlueRoomThreeAction::BlueRoomThreeAction(ItemTable *iTable) : AbstractRoomAction(iTable) {}

ActionResults *BlueRoomThreeAction::Pick() {
    if ((commands->getMainItem() == BALL && commands->getActedOnItem() == PIPE)
            || (commands->getMainItem() == PIPE && commands->getActedOnItem() == BALL)) {
        itemList->getValue(BALL)->setLocation(HIDDEN);
        return new ActionResults(CURRENT, "The ball dissapears and you here a large click as the door unlocks to your north.");
    } else {
        return AbstractRoomAction::Pick();
    }
}

ActionResults * BlueRoomThreeAction::Go() {

    if (commands->getMainItem() == NORTH) {
        if(itemList->getValue(BALL)->getLocation() == HIDDEN) {
            return new ActionResults(B_ROOM4, "You go north.\n");
        } else {
            return new ActionResults(CURRENT, "The door is locked in what looks like a mechanical way, with a series of pipes "
                    "anchoring it to the walls.");
        }
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(B_ROOM2, "You go south.\n");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    return new ActionResults(CURRENT,"You can't go there.\n");

}

ActionResults *BlueRoomThreeAction::Look() {
    if (commands->getMainItem() == PIPE) {
        return new ActionResults(CURRENT, "The pipes appear to be some complex, interconnected mechanism, each about 3 inches in diameter.");
    } else {
        return AbstractRoomAction::Look();
    }
}
