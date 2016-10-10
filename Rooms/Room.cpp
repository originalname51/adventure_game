//
// Created by rob on 10/4/16.
//

#include "Room.h"
//http://stackoverflow.com/questions/21163188/most-simple-but-complete-cmake-example

Room::Room(){};
Room::Room(std::string rn, ItemTable * itable, bool sld) {

    table = itable;
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();
}

void Room::parseData() {
    std::ifstream myfile(roomName);
    description description = ROOM_STATE_0;
    if (myfile.is_open()) {
        std::string line;
        while (getline(myfile, line)) {
            if (line == "#UPDATED#") {
                description = ROOM_STATE_1;
            } else if (line == "#UPDATED_1#") {
                description = ROOM_STATE_2;
            } else if (description == ROOM_STATE_0) {
                defaultDescription += line;
                defaultDescription += "\n";
            } else if (description == ROOM_STATE_1) {
                updatedDescription += line;
                updatedDescription += "\n";
            }
        }
    }
}