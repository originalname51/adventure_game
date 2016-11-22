//
// Created by rob on 11/19/16.
//

#include "BlueRoomOne.h"

BlueRoomOne::BlueRoomOne(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "GreenRoomFour";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string BlueRoomOne::getDescription(bool longform) {
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}