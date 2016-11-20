//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_BLUEROOMONE_H
#define ITEM_TEST_BLUEROOMONE_H


#include "Room.h"

class BlueRoomOne : public Room {

private:
    std::string testing();
public:
    BlueRoomOne(std::string, ItemTable *iList, bool f);
    std::string getDescription();
};



#endif //ITEM_TEST_BLUEROOMONE_H
