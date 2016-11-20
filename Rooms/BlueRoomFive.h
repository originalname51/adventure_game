//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_BLUEROOMFIVE_H
#define ITEM_TEST_BLUEROOMFIVE_H


#include "Room.h"

class BlueRoomFive: public Room {

private:
    std::string testing();
public:
    BlueRoomFive(std::string, ItemTable *iList, bool f);
    std::string getDescription();
};


#endif //ITEM_TEST_BLUEROOMFIVE_H
