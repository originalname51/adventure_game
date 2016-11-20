//
// Created by rob on 11/20/16.
//

#include "WhiteRoomFour.h"

WhiteRoomFour::WhiteRoomFour(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    displayName = "Fox, Goose, and Bean Puzzle Room";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();
}

std::string WhiteRoomFour::getDescription(){
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}

std::string WhiteRoomFour::testing(){
    return "I am in testing";
}
