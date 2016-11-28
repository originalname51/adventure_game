//
// Created by rob on 11/19/16.
//

#include "GreenRoomThree.h"

GreenRoomThree::GreenRoomThree(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "GreenRoomTwo";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string GreenRoomThree::getDescription(bool longform) {
    if(longform){
        return rstate0;
    }
    if(table->getValue(CLEAN_BUCKET)->getLocation() == ACTIVE) {
        return rstate2;
    }
    return rstate1;
}


