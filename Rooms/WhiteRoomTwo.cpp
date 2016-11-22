//
// Created by rob on 11/20/16.
//

#include "WhiteRoomTwo.h"

WhiteRoomTwo::WhiteRoomTwo(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    displayName = "A World of Color";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();

}

std::string WhiteRoomTwo::getDescription(bool longform) {
    if(longform){
        return rstate0;
    }
    return rstate1;
}

std::string WhiteRoomTwo::testing(){
    return "I am in testing";
}