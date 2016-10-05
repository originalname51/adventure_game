//
// Created by rob on 10/4/16.
//

#ifndef ITEM_TEST_ROOM_H
#define ITEM_TEST_ROOM_H
#include <iostream>

enum room {START_ROOM, END_ROOM, CURRENT};
class Room {

public:
    std::string lookup(room r);
};


#endif //ITEM_TEST_ROOM_H
