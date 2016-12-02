//
// Created by rob on 10/10/16.
//

#include "GreenRoomOneAction.h"

GreenRoomOneAction::GreenRoomOneAction(ItemTable *iList, Command *commands) : AbstractRoomAction(iList,commands) {}

GreenRoomOneAction::GreenRoomOneAction(ItemTable *iList) : AbstractRoomAction(iList) {}


ActionResults * GreenRoomOneAction::Drop() {
    std::string information;
    if(commands->getMainItem() == GOOSE_TOKEN) {
        itemList->getValue(GOOSE_TOKEN)->setLocation(itemList->getValue(PLAYER)->getLocation());
        if (isRoomWon()) {
            itemList->getValue(G_ROOM_STATE)->setLocation(WON);
            information = "With the final token dropped on the floor the door unlocks. You can now go west!";
            return new ActionResults(CURRENT, information, FIREWORKS);
        } else {
            return new ActionResults(CURRENT,"You drop the goose token");
        }
    }else {
        return AbstractRoomAction::Drop();
    }
}

ActionResults *GreenRoomOneAction::Go() {

    if (commands->getMainItem() == WEST && itemList->getValue(G_ROOM_STATE)->getLocation() == NOT_WON) {
        return new ActionResults(CURRENT, "The path is blocked.\n");
    } else if (commands->getMainItem() == WEST && itemList->getValue(G_ROOM_STATE)->getLocation() == WON){
        itemList->getValue(PLAYER)->setLocation(G_ROOM2_BUCKET);
        return new ActionResults(G_ROOM2_BUCKET, "You move to the green room 2");
    } else if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go back, the door is locked.");
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
           return AbstractRoomAction::Use();        }

    return new ActionResults(CURRENT, information);
    }

bool GreenRoomOneAction::isRoomWon() const {
    return itemList->getValue(GOOSE_TOKEN)->getLocation() == G_ROOM1_SIDE2 && itemList->getValue(BEAN_TOKEN)->getLocation() == G_ROOM1_SIDE2 &&
           itemList->getValue(FOX_TOKEN)->getLocation() == G_ROOM1_SIDE2;
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