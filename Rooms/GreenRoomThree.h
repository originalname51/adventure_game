//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_GREENROOMTHREE_H
#define ITEM_TEST_GREENROOMTHREE_H


#include "Room.h"

class GreenRoomThree : public Room{
private:
    std::string testing();
public:
    GreenRoomThree(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};

#endif //ITEM_TEST_GREENROOMTHREE_H
