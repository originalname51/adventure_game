//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_BLUEROOMFOUR_H
#define ITEM_TEST_BLUEROOMFOUR_H


#include "Room.h"

class BlueRoomFour : public Room {

private:
    std::string testing();
public:
    BlueRoomFour(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};



#endif //ITEM_TEST_BLUEROOMFOUR_H
