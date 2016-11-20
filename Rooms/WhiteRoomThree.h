//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_WHITEROOMTHREE_H
#define ITEM_TEST_WHITEROOMTHREE_H


#include "Room.h"

class WhiteRoomThree : public Room {

private:
    std::string testing();
public:
    WhiteRoomThree(std::string, ItemTable *iList, bool f);
    std::string getDescription();
};
#endif //ITEM_TEST_WHITEROOMTHREE_H
