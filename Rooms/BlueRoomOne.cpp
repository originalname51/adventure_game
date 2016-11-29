//
// Created by rob on 11/19/16.
//

#include "BlueRoomOne.h"

BlueRoomOne::BlueRoomOne(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "Torched Arrays";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string BlueRoomOne::getDescription(bool longform) {
    if(table->getValue(STAIRS)->getLocation() == B_ROOM1) {
        return rstate2;
    }
    if(longform){
        return rstate0;
    } else
        return rstate1;
}