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
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}