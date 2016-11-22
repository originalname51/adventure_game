//
// Created by rob on 10/10/16.
//

#include "StartRoom.h"

StartRoom::StartRoom(std::string rn, ItemTable *iList, bool sld) {
    table = iList;
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();

}

std::string StartRoom::getDescription(bool longform) {
    return testing();
}

std::string StartRoom::testing(){
    return "I am in testing";
}