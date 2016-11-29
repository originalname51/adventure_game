//
// Created by rob on 11/20/16.
//

#include "BlueRoomFive.h"

BlueRoomFive::BlueRoomFive(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "Pitch Blue";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string BlueRoomFive::getDescription(bool longform) {
    if(table->getValue(TABLET)->getLocation() == HIDDEN) {
        return rstate2;
    }
    if(longform){
        return rstate0;
    } else
        return rstate1;
}