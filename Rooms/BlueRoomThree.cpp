//
// Created by rob on 11/19/16.
//

#include "BlueRoomThree.h"

BlueRoomThree::BlueRoomThree(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "Iced Piping";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string BlueRoomThree::getDescription(bool longform) {
    if(longform){
        return rstate0;
    }
    return rstate1;
}