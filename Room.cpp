//
// Created by rob on 10/4/16.
//

#include "Room.h"
//http://stackoverflow.com/questions/21163188/most-simple-but-complete-cmake-example
enum description {
    DEFAULT, STATE_1, STATE_2
};

Room::Room(std::string room) {

    room = std::string(RESOURCES_PATH) + room;
    std::ifstream myfile(room);
    description description = DEFAULT;
    if (myfile.is_open()) {
        std::string line;
        while (getline(myfile, line)) {
            if (line == "#UPDATED#") {
                description = STATE_1;
            } else if (line == "#UPDATED_1#") {
                description = STATE_2;
            } else if (description == DEFAULT) {
                defaultDescription += line;
                defaultDescription += "\n";
            } else if (description == STATE_1) {
                updatedDescription += line;
                updatedDescription += "\n";
            }
        }
    }
    std::cout << updatedDescription;
    std::cout << defaultDescription;
}

std::string Room::getDefault(){return defaultDescription;}

std::string Room::getUpdated(){return defaultDescription;}

