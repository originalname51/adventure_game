//
// Created by rob on 11/20/16.
//

#include "WhiteRoomFiveAction.h"

WhiteRoomFiveAction::WhiteRoomFiveAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

WhiteRoomFiveAction::WhiteRoomFiveAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *WhiteRoomFiveAction::Pick() {
    if(commands->getMainItem() == BOWL) {
        return new ActionResults(CURRENT, "You can't pick it up. Its stuck to the table!");
    }
    else if(commands->getMainItem() == PITCHER && itemList->getValue(PITCHER)->getLocation() != BACKPACK){
        itemList->getValue(PITCHER)->setLocation(BACKPACK);
        return new ActionResults(CURRENT, "Cool... you can use this at your next party. It seems to be carrying some unknown, dark liquid");
    }
    else {
        return AbstractRoomAction::Pick();
    }
}

ActionResults *WhiteRoomFiveAction::Look() {
    return AbstractRoomAction::Look();
}

ActionResults *WhiteRoomFiveAction::Use() {
    if (commands->getMainItem() == PITCHER && itemList->getValue(PITCHER)->getLocation() == BACKPACK && commands->getActedOnItem() == BOWL) {
        roomWon = true;
        return new ActionResults (CURRENT, "You pour your pitcher full of mysterious liquid into the bowl. As you are doing this, the bright bowl starts to project a balanced light, "
                "then sinks into the table. A message below the bowl says ‘Return the crystal to the three keys room. You feel light, and notice the wall behind you has changed to the "
                "room you woke up in.");
    } else {
        return AbstractRoomAction::Use();
    }
}

ActionResults *WhiteRoomFiveAction::Go() {

        if(roomWon) {
            itemList->getValue(WHITE_KEY)->setLocation(HIDDEN);
            return new ActionResults(THREE_KEY_ROOM, "You find yourself in the key room");
        }
        else if(commands->getMainItem() == SOUTH) {
            return new ActionResults(W_ROOM4, "You travel south");
        } else {
            return new ActionResults(CURRENT, "You can't go that way");
        }
}

ActionResults *WhiteRoomFiveAction::Drop() {
    if(commands->getMainItem() == PITCHER && itemList->getValue(PITCHER)->getLocation() == BACKPACK && commands->getActedOnItem() == BOWL){
        roomWon = true;
        itemList->getValue(PITCHER)->setLocation(W_ROOM5);
        return new ActionResults (CURRENT, "You pour your pitcher full of mysterious liquid into the bowl. As you are doing this, the bright bowl starts to project a balanced light, "
                "then sinks into the table. A message below the bowl says \"Return the crystal to the three keys room.\" You feel light, and notice the wall behind you has changed to the "
                "room you woke up in.");
    }
    else if(commands->getMainItem() == PITCHER && itemList->getValue(PITCHER)->getLocation() == BACKPACK){
        itemList->getValue(PITCHER)->setLocation(W_ROOM5);
        return new ActionResults(CURRENT, "The pitcher makes a solid thud on the floor. A little bit of the black liquid spills on the ground. The spilled liquid absorbs the light around it.");
    }
    else {
        return AbstractRoomAction::Drop();
    }
}

ActionResults *WhiteRoomFiveAction::Throw() {
    if(commands->getMainItem() == PITCHER && itemList->getValue(PITCHER)->getLocation() == BACKPACK){
        itemList->getValue(PITCHER)->setLocation(W_ROOM5);
        return new ActionResults(CURRENT, "The pitcher seems to defy gravity. It drops to the floor and spills some of its contents. The light around the pitcher seems to be absorbed by its mysterious liquid.");
    }
    else {
        return AbstractRoomAction::Throw();
    }
}

ActionResults *WhiteRoomFiveAction::Rest() {
    return new ActionResults(CURRENT, "You sit down next to the bowl. What could you pour into it?");
}
