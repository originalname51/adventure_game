//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_BLUEROOMTHREE_H
#define ITEM_TEST_BLUEROOMTHREE_H


#include "Room.h"

class BlueRoomThree: public Room {

private:
    std::string testing();
public:
    BlueRoomThree(std::string, ItemTable *iList, bool f);
    std::string getDescription();
};



#endif //ITEM_TEST_BLUEROOMTHREE_H
