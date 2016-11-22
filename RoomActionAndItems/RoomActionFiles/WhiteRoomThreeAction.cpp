//
// Created by rob on 11/20/16.
//

#include "WhiteRoomThreeAction.h"

WhiteRoomThreeAction::WhiteRoomThreeAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

WhiteRoomThreeAction::WhiteRoomThreeAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *WhiteRoomThreeAction::Go() {
    if (commands->getMainItem() == NORTH) {
        if(itemList->getValue(DOOR_W1)->getLocation() == UNLOCKED) {
            return new ActionResults(W_ROOM4, "You move to the fourth");
        } else {
            return new ActionResults(CURRENT, "The door is locked");
        }
    } else if (commands->getMainItem() == SOUTH)
    {
        return new ActionResults(W_ROOM2, "You go back");
    } else {
        return new ActionResults(CURRENT, "You can't go there");
    }

}

ActionResults *WhiteRoomThreeAction::Use() {
    if (commands->getMainItem() == DISCUS && commands->getActedOnItem() == ROPE) {
        discusUsedOnPillar = true;
        return new ActionResults(CURRENT, "You re-direct the light to the rope. If only you had a little more power you could break the rope and"
                "move to teh next room!", FIREWORKS);
    } else if (commands->getMainItem() == POWER_CRYSTAL && commands->getActedOnItem() == ROPE && discusUsedOnPillar) {
        itemList->getValue(DOOR_W1)->setLocation(UNLOCKED);
        return new ActionResults(CURRENT, "The Rope breaks and the door opens. ", FIREWORKS);
    } else {
        return AbstractRoomAction::Use();
    }
}

ActionResults *WhiteRoomThreeAction::Look() {
    if (commands->getMainItem() == ROPE) {
        return new ActionResults(CURRENT, "You see a rope connecting the two rooms. You should try and break it.");
    }
    return AbstractRoomAction::Look();
}
