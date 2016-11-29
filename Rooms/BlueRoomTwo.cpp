//
// Created by rob on 11/19/16.
//

#include "BlueRoomTwo.h"

BlueRoomTwo::BlueRoomTwo(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "Mist and Mirrors";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string BlueRoomTwo::getDescription(bool longform) {
    if(table->getValue(FISH)->getLocation() != HIDDEN) {
        return rstate2;
    }
    if(longform){
        return rstate0;
    } else
        return rstate1;
}