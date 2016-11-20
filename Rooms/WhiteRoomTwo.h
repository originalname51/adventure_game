//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_WHITEROOMTWO_H
#define ITEM_TEST_WHITEROOMTWO_H


#include "Room.h"

class WhiteRoomTwo : public Room {

private:
    std::string testing();
public:
    WhiteRoomTwo(std::string, ItemTable *iList, bool f);
    std::string getDescription();
};



#endif //ITEM_TEST_WHITEROOMTWO_H