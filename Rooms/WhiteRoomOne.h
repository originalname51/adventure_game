//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_WHITEROOMONE_H
#define ITEM_TEST_WHITEROOMONE_H


#include "Room.h"

class WhiteRoomOne : public Room {

private:
    std::string testing();
public:
    WhiteRoomOne(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};



#endif //ITEM_TEST_WHITEROOMONE_H
