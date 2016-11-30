//
// Created by rob on 11/19/16.
//

#include "GreenRoomThreeAction.h"

GreenRoomThreeAction::GreenRoomThreeAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}

GreenRoomThreeAction::GreenRoomThreeAction(ItemTable *iList) : AbstractRoomAction(iList) {

}


ActionResults * GreenRoomThreeAction::Look() {
    if(commands->getMainItem() == BASIN) {
        return new ActionResults(CURRENT, "The basin looks clean. You feel you can clean anything here.");
    } else {
        return AbstractRoomAction::Look();
    }

}

ActionResults *GreenRoomThreeAction::Use() {

    if(!(itemList->getValue(commands->getMainItem())->getLocation() == BACKPACK || itemList->getValue(PLAYER)->getLocation() == itemList->getValue(commands->getMainItem())->getLocation()))
    {
        return new ActionResults(CURRENT, "No item to use here");
    }

    if((commands->getMainItem() == BUCKET && commands->getActedOnItem() == BASIN) ||
            (commands->getMainItem() == BASIN && commands->getActedOnItem() == BUCKET)) {

        itemList->getValue(BLOOD_BUCKET)->setLocation(INACTIVE);
        itemList->getValue(CLEAN_BUCKET)->setLocation(ACTIVE);
        return new ActionResults(CURRENT, "You cleaned the bloody bucket! You now have a clean bucket filled with water!");
    }
    else if ((commands->getMainItem() == BASIN || commands->getActedOnItem() == BASIN) &&
                                                         (commands->getMainItem() == CLEAN_BUCKET || commands->getActedOnItem() == CLEAN_BUCKET))
    {
        return new ActionResults(CURRENT,"You pour out and re-fill the bucket with ice-cold water");
    } else {
        return AbstractRoomAction::Use();
    }
}

ActionResults *GreenRoomThreeAction::Go() {

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(G_ROOM2_BUCKET, "You go north.");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(CURRENT, "There is a wall, you can only go north.");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You you can only go north.");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go north.");
    }
    return new ActionResults(CURRENT,"You can't go there.");
}
