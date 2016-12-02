//
// Created by rob on 11/20/16.
//

#include "BlueRoomFiveAction.h"

BlueRoomFiveAction::BlueRoomFiveAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

BlueRoomFiveAction::BlueRoomFiveAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *BlueRoomFiveAction::Look() {
    std::string information;

    switch(commands->getMainItem()) {
        case TABLET :
            information = "There are faint dust marks on the tablet. They seem to be about the size of the hanging statue’s base.";
            break;
        case STATUE :
            information =  "You inspect the statue closely. It is a small ugly statue made of solid precious metal, though you can't tell which variety.";
            break;
        case BOX :
            if (itemList->getValue(BOX)->getLocation() != HIDDEN) {
                information = "You see a large stone box.";
                break;
            }
        default:
            return AbstractRoomAction::Look();
    }

    return new ActionResults(CURRENT, information);
}

ActionResults *BlueRoomFiveAction::Go(){
    if(roomWon) {
        itemList->getValue(BLUE_KEY)->setLocation(HIDDEN);
        return new ActionResults(THREE_KEY_ROOM, "You find yourself in the key room");
    }else if (commands->getMainItem() == NORTH) {
        return new ActionResults(CURRENT, "There is no door or exit to the north, only a box.");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(B_ROOM4, "You travel back from where you came...");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south...");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south...");
    }
    return new ActionResults(CURRENT,"You can't go there.");

}

ActionResults *BlueRoomFiveAction::Use() {
    if(commands->getMainItem() == TORCH) {
        return new ActionResults(CURRENT, "You've already used the torch.");
    }else if(commands->getMainItem() == STATUE){
        return new ActionResults(CURRENT, "The statue awaits your action. You attempt to trigger its innate action. Kind of a stand off I guess. Maybe try something else?");
    }else {
        return AbstractRoomAction::Use();
    }
}

ActionResults * BlueRoomFiveAction::Open() {
    if (commands->getMainItem() == BOX && itemList->getValue(BOX)->getLocation() != HIDDEN) {
        roomWon = true;
        itemList->getValue(BLUE_KEY)->setLocation(HIDDEN);
        return new ActionResults(CURRENT, "You see a message inside the box that instructs you \"return and use a discus where this whole thing started.\""
        "You hear a strange voice announce that all paths lead to the center of existence. Just go.", FIREWORKS);
    }
    if(commands->getMainItem() == STATUE){
        return new ActionResults(CURRENT, "It doesn't open. No one was present to see you, but you feel like the statue looks more smug.");
    }
    return AbstractRoomAction::Open();
}

ActionResults * BlueRoomFiveAction::Pick() {
    if(commands->getMainItem() == TABLET) {
       return new ActionResults(CURRENT, "You can't pick up the tablet, it is far too heavy.");
    }

    if(commands->getMainItem() == STATUE){
        itemList->getValue(STATUE)->setLocation(BACKPACK);
        return new ActionResults(CURRENT, "You lift the statue with considerable effort and are now holding it.");
    }
    return AbstractRoomAction::Pick();
}

ActionResults * BlueRoomFiveAction::Action() {
    if((commands->getMainItem() == TORCH) && ((commands->getAction() == USE) && (!torchUsed))){
        torchUsed = true;
        return new ActionResults(CURRENT, "You point the torch meaningfully and the room illuminates in front of you. The room indeed has a stonework floor. There is a stone tablet in the center, with a small statue suspended above it. There is a heavy stone box near the back of the room with no handle.", FIREWORKS);
    }else if(commands->getAction() != GO && !torchUsed) {
        return new ActionResults(CURRENT, "It's too dark to do anything here! You need to find a way to light the room!");
    } else if(commands->getAction() == GO && itemList->getValue(BOX)->getLocation() != HIDDEN) {
        return new ActionResults(THREE_KEY_ROOM, "You head back.");
    } else {
        return AbstractRoomAction::Action();
    }
}

ActionResults * BlueRoomFiveAction::Drop() {
    if (commands->getMainItem() == STATUE && commands->getActedOnItem() == TABLET) {
        itemList->getValue(BOX)->setLocation(B_ROOM5);
        itemList->getValue(TABLET)->setLocation(HIDDEN);
        return new ActionResults(CURRENT, "You place the statue on the center of the tablet. The tablet begins to make a grinding sound and slowly rotates into the floor until all you can see is the statue. A moment later, you hear a loud clicking sound from the large stone box. You wonder what is inside.");
    } else if(commands->getMainItem() == STATUE){
        itemList->getValue(STATUE)->setLocation(B_ROOM5);
        return new ActionResults(CURRENT, "You try and drop the statue without hurting yourself, narrowly missing your toe. It sits staring up at you.");
    }else {
        return AbstractRoomAction::Drop();
    }
}

ActionResults * BlueRoomFiveAction::Throw() {
    if(commands->getMainItem() == STATUE){
        itemList->getValue(STATUE)->setLocation(B_ROOM5);
        return new ActionResults(CURRENT, "Uh yep, you throw the statue as hard as you can. It sails forward and bangs to the floor about a foot from you.");
    } else {
        return AbstractRoomAction::Throw();
    }
}
