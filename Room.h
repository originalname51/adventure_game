//
// Created by rob on 10/4/16.
//

#ifndef ITEM_TEST_ROOM_H
#define ITEM_TEST_ROOM_H
#include <iostream>
#include <assert.h>
#include <fstream>
#include "configuration.h"

enum room {START_ROOM, END_ROOM, CURRENT};
class Room {
    std::string defaultDescription;
    std::string updatedDescription;
public:
    Room(std::string);
    std::string getDefault();
    std::string getUpdated();
};


#endif //ITEM_TEST_ROOM_H
