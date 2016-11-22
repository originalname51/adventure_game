//
// Created by rob on 11/19/16.
//

#include "GreenRoomFour.h"
GreenRoomFour::GreenRoomFour(std::string rn, ItemTable *iList, bool f) {
    table = iList;
    displayName = "GreenRoomFour";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = f;
    parseData();
}

std::string GreenRoomFour::getDescription(bool longform) {
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}