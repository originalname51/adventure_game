//
// Created by rob on 11/20/16.
//

#include "WhiteRoomFour.h"

WhiteRoomFour::WhiteRoomFour(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    displayName = "Over Exposure";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();
}

std::string WhiteRoomFour::getDescription(bool longform) {
    if(table->getValue(TORCH)->getLocation() != BACKPACK){
        return rstate2;
    }
    else if(longform){
        return rstate0;
    }
    else {
        return rstate1;
    }
}

std::string WhiteRoomFour::testing(){
    return "I am in testing";
}
