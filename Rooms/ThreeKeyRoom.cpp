//
// Created by rob on 10/10/16.
//

#include "ThreeKeyRoom.h"
ThreeKeyRoom::ThreeKeyRoom(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    displayName = "The start room.";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();

}

std::string ThreeKeyRoom::getDescription(bool longform) {
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}

std::string ThreeKeyRoom::testing(){
    return "I am in testing";
}