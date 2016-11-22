//
// Created by rob on 11/20/16.
//

#include "WhiteRoomThree.h"

WhiteRoomThree::WhiteRoomThree(std::string rn, ItemTable *iList, bool sld) {
        table = iList;
        displayName = "A Little Kid & A Magnifying Glass";
        roomName = std::string(RESOURCES_PATH) + rn;
        showLongDescription = sld;
        parseData();
}

std::string WhiteRoomThree::getDescription(bool longform) {
    if(longform){
        return rstate0;
    }
    return rstate1;
}

std::string WhiteRoomThree::testing(){
    return "I am in testing";
}