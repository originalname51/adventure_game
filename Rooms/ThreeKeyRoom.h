//
// Created by rob on 10/10/16.
//

#ifndef ITEM_TEST_KEYROOM_H
#define ITEM_TEST_KEYROOM_H


#include "Room.h"

class ThreeKeyRoom : public Room{
private:
    std::string testing();
public:
    ThreeKeyRoom(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};


#endif //ITEM_TEST_KEYROOM_H
