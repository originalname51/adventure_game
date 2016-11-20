//
// Created by rob on 11/19/16.
//

#include "BlueRoomThree.h"

BlueRoomThree::BlueRoomThree(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "GreenRoomFour";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string BlueRoomThree::getDescription() {
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}