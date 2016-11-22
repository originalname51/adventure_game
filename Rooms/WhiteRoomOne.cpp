//
// Created by rob on 11/19/16.
//

#include "WhiteRoomOne.h"
WhiteRoomOne::WhiteRoomOne(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    displayName = "Shadows and Reflections";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();

}

std::string WhiteRoomOne::getDescription(bool longform) {
    if(longform){
        return rstate0;
    }
    return rstate1;
}

std::string WhiteRoomOne::testing(){
    return "I am in testing";
}