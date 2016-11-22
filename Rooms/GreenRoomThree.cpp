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
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}


