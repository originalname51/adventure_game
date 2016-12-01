//
// Created by rob on 11/20/16.
//

#include "WhiteRoomFourAction.h"

WhiteRoomFourAction::WhiteRoomFourAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

WhiteRoomFourAction::WhiteRoomFourAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *WhiteRoomFourAction::Go() {
    if(itemList->getValue(TORCH)->getLocation() == BACKPACK){
        return new ActionResults(CURRENT, "Your blind, as in you can't see, as in no cheating, as in there is probably something in your backpack that you should drop.");
    }
    else {
        if(commands->getMainItem() == WEST) {
            return new ActionResults(W_ROOM3, "You travel back");
        } else if (commands->getMainItem() == NORTH){
            return new ActionResults(W_ROOM5, "You travel north");
        } else {
            return new ActionResults(CURRENT, "Ah, ah, ah, YOU DID'T SAY THE MAGIC WORD!");
        }
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
        itemList->getValue(TORCH)->setLocation(W_ROOM4);
        return new ActionResults(CURRENT, "Yah, putting a lit torch into your backpack was probably not your finest moment."
                "There is a door to the north that is wide open that you previously could not see.");
    }
    return AbstractRoomAction::Drop();
}

ActionResults *WhiteRoomFourAction::Pick() {
    if(commands->getMainItem() == TORCH && itemList->getValue(TORCH)->getLocation() == W_ROOM4){
        itemList->getValue(TORCH)->setLocation(BACKPACK);
        return new ActionResults(CURRENT, "You're blinded by your newly acquired torch. Maybe there is such thing as too much light?");
    }
    else {
        return AbstractRoomAction::Pick();
    }
}

ActionResults *WhiteRoomFourAction::Throw() {
    if(commands->getMainItem() == TORCH && itemList->getValue(TORCH)->getLocation() == BACKPACK){
        itemList->getValue(TORCH)->setLocation(W_ROOM4);
        return new ActionResults(CURRENT, "With a good chuck your torch glides across the room. Suddenly it is easier to see the contents of the room."
                "There is a door to the north that is wide open that you previously could not see.");
    }
    else {
        return AbstractRoomAction::Throw();
    }

}


