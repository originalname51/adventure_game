//
// Created by rob on 11/20/16.
//

#include "BlueRoomFive.h"

BlueRoomFive::BlueRoomFive(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "GreenRoomFour";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string BlueRoomFive::getDescription(bool longform) {
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}