//
// Created by rob on 10/30/16.
//

#ifndef ITEM_TEST_GREENROOMTWO_H
#define ITEM_TEST_GREENROOMTWO_H


#include "Room.h"

class GreenRoomTwo : public Room{

public:
    GreenRoomTwo(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};


#endif //ITEM_TEST_GREENROOMTWO_H
