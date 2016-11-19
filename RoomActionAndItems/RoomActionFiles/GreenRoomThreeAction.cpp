//
// Created by rob on 11/19/16.
//

#include "GreenRoomThreeAction.h"

GreenRoomThreeAction::GreenRoomThreeAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}

GreenRoomThreeAction::GreenRoomThreeAction(ItemTable *iList) : AbstractRoomAction(iList) {

}

ActionResults *GreenRoomThreeAction::Use() {

    if(itemList->getValue(commands->getMainItem())->getLocation() != BACKPACK || itemList->getValue(commands->getMainItem())->getLocation() != G_ROOM3_BASIN)
    {
        return new ActionResults(CURRENT, "No item to use here");
    }

    if((commands->getMainItem() == BASIN || commands->getActedOnItem() == BASIN) &&
            (commands->getMainItem() == BLOOD_BUCKET || commands->getActedOnItem() == BLOOD_BUCKET)) {

        itemList->getValue(BLOOD_BUCKET)->setLocation(HIDDEN);
        itemList->getValue(CLEAN_BUCKET)->setLocation(BACKPACK);
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
        return new ActionResults(G_ROOM2_BUCKET, "You go north.\n");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(CURRENT, "You can't go south, you can only go north.\n");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go north.\n");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go north.\n");
    }
    return new ActionResults(CURRENT,"You can't go there.\n");
}
