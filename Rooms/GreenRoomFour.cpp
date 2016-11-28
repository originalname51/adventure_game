//
// Created by rob on 11/19/16.
//

#include "GreenRoomFour.h"
GreenRoomFour::GreenRoomFour(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "GreenRoomFour";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string GreenRoomFour::getDescription(bool longform) {
    if(longform){
        return rstate0;
    }
    if(table->getValue(KID)->getLocation() == HIDDEN) {
        return rstate2;
    }
    return rstate1;
}