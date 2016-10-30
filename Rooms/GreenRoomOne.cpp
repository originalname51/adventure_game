//
// Created by rob on 10/29/16.
//

#include "GreenRoomOne.h"
GreenRoomOne::GreenRoomOne(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    displayName = "Fox, Goose, and Bean Puzzle Room";
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();

}

std::string GreenRoomOne::getDescription(){
    if(showLongDescription){
        return rstate0;
    }
    return rstate1;
}

std::string GreenRoomOne::testing(){
    return "I am in testing";
}