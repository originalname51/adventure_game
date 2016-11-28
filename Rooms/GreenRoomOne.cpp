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

std::string GreenRoomOne::getDescription(bool longform) {
    if(table->getValue(G_ROOM_STATE)->getLocation() == WON) {
        return rstate2;
    }
    if(longform){
        return rstate0;
    } else
    return rstate1;
}
