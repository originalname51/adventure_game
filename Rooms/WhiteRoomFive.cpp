//
// Created by rob on 11/20/16.
//

#include "WhiteRoomFive.h"

WhiteRoomFive::WhiteRoomFive(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    displayName = "The Darkness of Light";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();
}

std::string WhiteRoomFive::getDescription(bool longform) {
    if(table->getValue(PITCHER)->getLocation() == WON){
        return rstate2;
    }
    else if(longform){
        return rstate0;
    }
    else {
        return rstate1;
    }
}

std::string WhiteRoomFive::testing(){
    return "I am in testing";
}
