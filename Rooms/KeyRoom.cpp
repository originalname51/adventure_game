//
// Created by rob on 10/10/16.
//

#include "KeyRoom.h"
KeyRoom::KeyRoom(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();

}

std::string KeyRoom::getDescription(){
    if(showLongDescription){
        return rstate0;
    }
    if(table->getValue(SHIH_TZU)->getLocation() == WATER_ROOM_UNDERWATER){
        return "Items able to effect gamestate\n" + rstate1;
    }
    return rstate1;
}

std::string KeyRoom::testing(){
    return "I am in testing";
}