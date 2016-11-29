//
// Created by rob on 10/4/16.
//

#include "Room.h"
//http://stackoverflow.com/questions/21163188/most-simple-but-complete-cmake-example

Room::Room(){};
Room::Room(std::string rn, ItemTable * itable, bool sld) {

    table = itable;
    displayName = rn;
    roomName = std::string(RESOURCES_PATH) + rn;
    showLongDescription = sld;
    parseData();
}
std::string Room::getRoomName() {
    return displayName;
}
void Room::parseData() {
    std::ifstream myfile(roomName);
    description description = ROOM_STATE_0;
    if (myfile.is_open()) {
        std::string line;
        while (getline(myfile, line)) {
            if (line == "#ROOM_STATE_1#") {
                description = ROOM_STATE_1;
            } else if (line == "#ROOM_STATE_2#") {
                description = ROOM_STATE_2;
            } else if (description == ROOM_STATE_0) {
                rstate0 += line;
                rstate0 += "\n";
            } else if (description == ROOM_STATE_1) {
                rstate1 += line;
                rstate1 += "\n";
            } else if(description == ROOM_STATE_2) {
                rstate2 += line;
                rstate2 += "\n";
            }
        }
    }
    myfile.close();
}