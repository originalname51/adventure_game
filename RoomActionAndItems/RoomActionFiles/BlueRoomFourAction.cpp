//
// Created by rob on 11/19/16.
//

#include "BlueRoomFourAction.h"

BlueRoomFourAction::BlueRoomFourAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

BlueRoomFourAction::BlueRoomFourAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *BlueRoomFourAction::Look() {

    std::string information;

    switch(commands->getMainItem()) {
        case ROPE:
            information = "The rope appears to be attached to the floor in the middle of the room. There seems to be enough to extend toward each pillar.";
            break;
        case WHITE_PILLAR:
            information = "There appears to be a small hook near the middle of the pillar. Maybe you could tie something to it.";
            break;
        case BLACK_PILLAR:
            information = "There appears to be a small hook near the middle of the pillar. Maybe you could tie something to it.";
            break;
        default:
            return AbstractRoomAction::Look();
    }
    return new ActionResults(CURRENT, information);
}

ActionResults *BlueRoomFourAction::Go() {

    if (commands->getMainItem() == NORTH && (itemList->getValue(BALL)->getLocation() == WON)) {
        return new ActionResults(B_ROOM5, "The walls have shifted around and revealed a door on the north wall that you now use, heading north.");
    }
    if (commands->getMainItem() == NORTH && (itemList->getValue(ROPE)->getLocation() != HIDDEN)) {
        return new ActionResults(CURRENT, "You don't see anything to the north. Maybe you should explore these pillars a bit more.");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(B_ROOM3, "You head back to the strange icy room.");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south...");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south...");
    }
    return new ActionResults(CURRENT,"You can't go there.");

}

ActionResults *BlueRoomFourAction::Pick() {

    if(commands->getMainItem() == WHITE_PILLAR || commands->getMainItem() == BLACK_PILLAR)
    {
        return new ActionResults(CURRENT,"You can't pick up that pillar!");
    } else if (commands->getMainItem() == ROPE){
        return new ActionResults(CURRENT, "You attempt to pickup the rope, but it appears to be attached to the floor in the middle of the room. "
                "There seems to be enough to extend toward each pillar.");
    } else {
        return AbstractRoomAction::Pick();
    }
}

ActionResults * BlueRoomFourAction::Throw() {
    if(commands->getMainItem() == ROPE && itemList->getValue(ROPE)->getLocation() != HIDDEN){
        return new ActionResults(CURRENT, "You comically try and toss the rope as far as you can. Being attached to the floor, it doesn't work well.");
    } else {
        return AbstractRoomAction::Throw();
    }
}

ActionResults * BlueRoomFourAction::Use() {
    std::string information;
    switch(commands->getMainItem()) {
        case ROPE :
            if (commands->getActedOnItem() == WHITE_PILLAR) {
                if(blackPillarRope){
                    whitePillarRope = true;
                    itemList->getValue(ROPE)->setLocation(HIDDEN);
                    itemList->getValue(BALL)->setLocation(WON);
                    information = "You tie the other end of the rope to the other pillar. "
                    "Suddenly the rope sinks into the ground, pulling the pillars to the center. "
                    "The walls have shifted and reveal a door to the north.";
                    break;
                }

                whitePillarRope = true;
                information = "You tie the rope to the hook on the white pillar";
            } else if (commands->getActedOnItem() == BLACK_PILLAR) {
                if(whitePillarRope){
                    blackPillarRope = true;
                    itemList->getValue(ROPE)->setLocation(HIDDEN);
                    itemList->getValue(BALL)->setLocation(WON);
                    information = "You tie the other end of the rope to the other pillar. "
                            "Suddenly the rope sinks into the ground, pulling the pillars to the center. "
                            "The walls have shifted and reveal a door to the north.";
                    break;
                }
                blackPillarRope = true;
                information = "You tie the rope to hook on the black pillar";
            } else {
                information= "You can't use the rope on that.";
            }
            break;
        default:
            return AbstractRoomAction::Use();
    }
    return new ActionResults(CURRENT, information);
}
