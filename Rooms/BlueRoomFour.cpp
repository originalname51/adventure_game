//
// Created by rob on 11/19/16.
//

#include "BlueRoomFour.h"

BlueRoomFour::BlueRoomFour(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "Pillars, Mirrors, and Rope";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string BlueRoomFour::getDescription(bool longform) {
    if(table->getValue(ROPE)->getLocation() == HIDDEN) {
        return rstate2;
    }
    if(longform){
        return rstate0;
    } else
        return rstate1;
}