//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_WHITEROOMFIVE_H
#define ITEM_TEST_WHITEROOMFIVE_H


#include "Room.h"

class WhiteRoomFive  : public Room {

private:
    std::string testing();
public:
    WhiteRoomFive(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};



#endif //ITEM_TEST_WHITEROOMFIVE_H
