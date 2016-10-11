//
// Created by rob on 10/10/16.
//

#ifndef ITEM_TEST_KEYROOM_H
#define ITEM_TEST_KEYROOM_H


#include "Room.h"

class KeyRoom : public Room{
private:
    std::string testing();
public:
    KeyRoom(std::string, ItemTable *iList, bool f);
    std::string getDescription();
};


#endif //ITEM_TEST_KEYROOM_H
