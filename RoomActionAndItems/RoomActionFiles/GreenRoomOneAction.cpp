//
// Created by rob on 10/10/16.
//

#include "GreenRoomOneAction.h"

GreenRoomOneAction::GreenRoomOneAction(ItemTable *iList, Command *commands) : AbstractRoomAction(iList,commands) {}

GreenRoomOneAction::GreenRoomOneAction(ItemTable *iList) : AbstractRoomAction(iList) {}

ActionResults *GreenRoomOneAction::Go() {

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(CURRENT, "You go north.");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(CURRENT, "You go south.");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You go east.");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "The path is blocked.\n");
    }
    return new ActionResults(CURRENT,"You can't go there.");
}


ActionResults *GreenRoomOneAction::Use() {
    std::string information;
    itemType item = commands->getMainItem();

    switch(item) {
        case G_BOAT :
            information = "You take the boat.";
            takeBoat();
            if(foxEatsGoose()) {
                information = "You take the boat. The fox token consumed the goose token."
                        "all tokens have been reset. Try again!";
                resetTokens();
            }
            else if(gooseEatsBean()) {
                information = "You take the boat. The goose token consumed the bean token."
                        "All tokens have been reset. Try again!";
                resetTokens();
            }
            break;
        default:
            information = "This item can not be used here.";
        }
    return new ActionResults(CURRENT, information);
    }


void GreenRoomOneAction::takeBoat() const {
    if (itemList->getValue(PLAYER)->getLocation() == G_ROOM1_SIDE1) {
                itemList->getValue(PLAYER)->setLocation(G_ROOM1_SIDE2);
            }
            else {
                itemList->getValue(PLAYER)->setLocation(G_ROOM1_SIDE1);
            }
}

void GreenRoomOneAction::resetTokens() const {
    itemList->getValue(FOX_TOKEN)->setLocation(G_ROOM1_SIDE1);
    itemList->getValue(GOOSE_TOKEN)->setLocation(G_ROOM1_SIDE1);
    itemList->getValue(BEAN_TOKEN)->setLocation(G_ROOM1_SIDE1);
}

bool GreenRoomOneAction::gooseEatsBean() const {
    return itemList->getValue(GOOSE_TOKEN)->getLocation() == itemList->getValue(BEAN_TOKEN)->getLocation()
           && itemList->getValue(PLAYER)->getLocation() != itemList->getValue(BEAN_TOKEN)->getLocation();
}

bool GreenRoomOneAction::foxEatsGoose() const {
    return itemList->getValue(FOX_TOKEN)->getLocation() == itemList->getValue(GOOSE_TOKEN)->getLocation()
           && itemList->getValue(PLAYER)->getLocation() != itemList->getValue(GOOSE_TOKEN)->getLocation();
}