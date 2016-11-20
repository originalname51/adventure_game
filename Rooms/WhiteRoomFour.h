//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_WHITEROOMFOUR_H
#define ITEM_TEST_WHITEROOMFOUR_H


#include "Room.h"

class WhiteRoomFour  : public Room {

private:
    std::string testing();
public:
    WhiteRoomFour(std::string, ItemTable *iList, bool f);
    std::string getDescription();
};


#endif //ITEM_TEST_WHITEROOMFOUR_H
