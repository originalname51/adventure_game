//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_BLUEROOMTWO_H
#define ITEM_TEST_BLUEROOMTWO_H


#include "Room.h"

class BlueRoomTwo : public Room {

private:
    std::string testing();
public:
    BlueRoomTwo(std::string, ItemTable *iList, bool f);
    std::string getDescription();
};




#endif //ITEM_TEST_BLUEROOMTWO_H
