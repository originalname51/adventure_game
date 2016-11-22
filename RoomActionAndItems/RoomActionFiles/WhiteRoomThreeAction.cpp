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
            return new ActionResults(W_ROOM4, "You move to the fourth room.");
        } else {
            return new ActionResults(CURRENT, "The door is locked");
        }
    } else if (commands->getMainItem() == SOUTH)
    {
        return new ActionResults(W_ROOM2, "Today must be backwards day, you backtrack to the previous room.");
    } else {
        return new ActionResults(CURRENT, "You can't go there");
    }

}

ActionResults *WhiteRoomThreeAction::Use() {
    if (commands->getMainItem() == DISCUS && commands->getActedOnItem() == ROPE) {
        discusUsedOnPillar = true;
        return new ActionResults(CURRENT, "You re-direct the light to the rope. If only you had a little more power you could break the rope and"
                "move to the next room!", FIREWORKS);
    } else if (commands->getMainItem() == POWER_CRYSTAL && commands->getActedOnItem() == ROPE && discusUsedOnPillar) {
        itemList->getValue(DOOR_W1)->setLocation(UNLOCKED);
        return new ActionResults(CURRENT, "The Rope breaks and the door opens.");
    } else if (commands->getMainItem() == POWER_CRYSTAL && commands->getActedOnItem() == ROPE && !discusUsedOnPillar){
        return new ActionResults(CURRENT, "The crystal is dull and ineffective and cutting anything other than jello.");
    }
    else {
        return AbstractRoomAction::Use();
    }
}

ActionResults *WhiteRoomThreeAction::Look() {
    if (commands->getMainItem() == ROPE) {
        return new ActionResults(CURRENT, "You see a rope connecting the two rooms. Hmm... if only you had a way to break it.");
    }
    return AbstractRoomAction::Look();
}

ActionResults *WhiteRoomThreeAction::Touch() {
    if (commands->getMainItem() == ROPE){
        return new ActionResults(CURRENT, "It is thick enough to hold a large rock in place, but frail enough to be severed.");
    }
    else if(commands->getMainItem() == LIGHT_PILLAR){
        return new ActionResults(CURRENT, "It's warm, like the sweats you wear after taking your last college final.");
    }
    else {
        return new ActionResults(CURRENT, "You touch it.");
    }
}

ActionResults *WhiteRoomThreeAction::Pick() {
    if (commands->getMainItem() == ROPE){
        return new ActionResults(CURRENT, "You tug at the rope, but despite your superhuman strength, nothing happens.");
    }
    else {
        return AbstractRoomAction::Pick();
    }
}
