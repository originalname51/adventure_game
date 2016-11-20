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

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(CURRENT, "You go north.\n");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(B_ROOM4, "You travel back from where you came..\n");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    return new ActionResults(CURRENT,"You can't go there.\n");

}

ActionResults *BlueRoomFiveAction::Use() {
    if(commands->getMainItem() == TORCH) {
        torchUsed = true;
        return new ActionResults(CURRENT, "The room illuminates in front of you. The room indeed has a stonework floor. "
                "There is a stone tablet in the center, with a small statue suspended above it. "
                "There is a heavy stone box near the back of the room with no handle.", FIREWORKS);
    } else {
        return AbstractRoomAction::Use();
    }
}

ActionResults *BlueRoomFiveAction::Open() {
    if (commands->getMainItem() == BOX && itemList->getValue(BOX)->getLocation() != HIDDEN) {
        return new ActionResults(CURRENT, "You see a message inside the box that "
                "instructs you return and use a discus ‘where this whole thing started.");
    }
    return AbstractRoomAction::Open();
}

ActionResults *BlueRoomFiveAction::Pick() {
    if(commands->getMainItem() == TABLET) {
       return new ActionResults(CURRENT, "You can't pick up the tablet.");
    }
    return AbstractRoomAction::Pick();
}

ActionResults *BlueRoomFiveAction::Action() {
    if(commands->getAction() != GO && torchUsed == false) {
        return new ActionResults(CURRENT, "It's too dark to do anything here! You need to find a way to light the room!");
    } else {
        return AbstractRoomAction::Action();
    }
}

ActionResults *BlueRoomFiveAction::Drop() {
    if (commands->getMainItem() == STATUE && commands->getActedOnItem() == TABLET) {
        itemList->getValue(BOX)->setLocation(B_ROOM5);
        return new ActionResults(CURRENT, "You place the statue on the center of the tablet. "
                "The tablet begins to make a grinding sound and slowly rotates into the floor until all you can see is the statue. "
                "A moment later, you hear a loud clicking sound as a large stone box comes into view. You wonder what is inside.", FIREWORKS);
    } else {
        return AbstractRoomAction::Drop();
    }
}
