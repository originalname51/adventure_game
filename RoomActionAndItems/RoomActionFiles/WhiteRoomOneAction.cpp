//
// Created by rob on 11/19/16.
//

#include "WhiteRoomOneAction.h"
#include "../AbstractRoomAction.h"

WhiteRoomOneAction::WhiteRoomOneAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}

WhiteRoomOneAction::WhiteRoomOneAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults * WhiteRoomOneAction::Use() {
    if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() == BACKPACK && commands->getActedOnItem() == LIGHT) {
        itemList->getValue(LADDER)->setLocation(W_ROOM1); //unhide ladder
        return new ActionResults(CURRENT, "Everything is rumbling! The floor drops out in part of the room and the top of an escape ladder juts out of the newly formed hole.");
    } else if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() != BACKPACK && commands->getActedOnItem() == LIGHT) {
        return new ActionResults(CURRENT, "Hmm... you seem to be fresh out of discuses, but there is one on the floor in front of you.");
    }
    else {
        return AbstractRoomAction::Use();
    }
}

ActionResults * WhiteRoomOneAction::Touch() {
    if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() == BACKPACK) {
        return new ActionResults(CURRENT, "It's slick, like butter. It's also shiny, as in reflective.");
    }
    else if(commands->getMainItem() == LIGHT){
        return new ActionResults(CURRENT, "You wave your hand aimlessly in the air. Good thing no one is watching.");
    }
    else {
        return new ActionResults(CURRENT, "That was touching, but ineffective.");
    }
}


ActionResults *WhiteRoomOneAction::Go() {
    if(commands->getMainItem() == LADDER && itemList->getValue(LADDER)->getLocation() != HIDDEN) {
        return new ActionResults(W_ROOM2, "You climb down the ladder");
    } else if(commands->getMainItem() == LIGHT){
        return new ActionResults(CURRENT, "You feel warmer, more content on where your life is going.");
    }
    else {
        return new ActionResults(CURRENT, "You don't go anywhere");
    }
}

ActionResults *WhiteRoomOneAction::Pick() {
    if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() != BACKPACK){
        itemList->getValue(DISCUS)->setLocation(BACKPACK);
        return new ActionResults(CURRENT, "You pick up the shiny discus.");
    }
    else {
        return AbstractRoomAction::Pick();
    }
}

ActionResults *WhiteRoomOneAction::Drop() {
    if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() == BACKPACK) {
        itemList->getValue(DISCUS)->setLocation(W_ROOM1);
        return new ActionResults(CURRENT, "The discus rolls around on the floor. You're backpack is .000024 kilograms lighter.");
    }
    else {
        return AbstractRoomAction::Drop();
    }
}

ActionResults *WhiteRoomOneAction::Throw() {
    if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() == BACKPACK && commands->getActedOnItem() == LIGHT){
        itemList->getValue(LADDER)->setLocation(W_ROOM1); //unhide ladder
        return new ActionResults(CURRENT, "Good shootin' Tex! The floor drops out in part of the room and the top of an escape ladder juts out of the newly formed hole.");
    }
    if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() == BACKPACK) {
        itemList->getValue(DISCUS)->setLocation(W_ROOM1);
        return new ActionResults(CURRENT, "The discus floats in the air like a frisbee before crashing into a wall and rolling around on the floor.");
    }
    else {
        return AbstractRoomAction::Throw();
    }
}
