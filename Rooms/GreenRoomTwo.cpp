//
// Created by rob on 10/30/16.
//

#include "GreenRoomTwo.h"
GreenRoomTwo::GreenRoomTwo(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    displayName = "GreenRoomTwo";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();
}

std::string GreenRoomTwo::getDescription(bool longform) {
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}

std::string GreenRoomTwo::testing(){
    return "I am in testing";
}