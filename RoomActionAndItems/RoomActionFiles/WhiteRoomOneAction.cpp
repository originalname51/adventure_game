//
// Created by rob on 11/19/16.
//

#include "WhiteRoomOneAction.h"

WhiteRoomOneAction::WhiteRoomOneAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}

WhiteRoomOneAction::WhiteRoomOneAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults * WhiteRoomOneAction::Use() {
    if(commands->getMainItem() == DISCUS && commands->getActedOnItem() == LIGHT) {
        itemList->getValue(LADDER)->setLocation(W_ROOM1); //unhide ladder
        return new ActionResults(CURRENT, "You solved it! A Ladder appears", FIREWORKS);
    } else {
        return AbstractRoomAction::Use();
    }
}


ActionResults *WhiteRoomOneAction::Go() {
    if(commands->getMainItem() == LADDER && itemList->getValue(LADDER)->getLocation() != HIDDEN) {
        return new ActionResults(W_ROOM2, "You climb down the ladder");
    } else {
        return new ActionResults(CURRENT, "You don't go anywhere");
    }
}
