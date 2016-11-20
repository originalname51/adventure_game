//
// Created by rob on 11/20/16.
//

#include "WhiteRoomFourAction.h"

WhiteRoomFourAction::WhiteRoomFourAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

WhiteRoomFourAction::WhiteRoomFourAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *WhiteRoomFourAction::Go() {

    if(commands->getMainItem() == SOUTH) {
        return new ActionResults(W_ROOM3, "You travel back");
    } else if (commands->getMainItem() == NORTH){
        return new ActionResults(W_ROOM5, "You travel north");
    } else {
        return new ActionResults(CURRENT, "You can't go that way");
    }
}

ActionResults *WhiteRoomFourAction::Action() {
    if(itemList->getValue(TORCH)->getLocation() == BACKPACK) {
        return new ActionResults(CURRENT, "It's too bright to do anything. You need to drop what is making light!(like a torch)");
    } else {
        return AbstractRoomAction::Action();
    }
}

ActionResults *WhiteRoomFourAction::Drop() {
    if (commands->getMainItem() == TORCH && itemList->getValue(TORCH)->getLocation() == BACKPACK) {
        return new ActionResults(CURRENT, "As the torch drops you feel you can see well enough to do any action you want."
                "There is a door that is wide open that you previously could not see.");
    }
    return AbstractRoomAction::Drop();
}
