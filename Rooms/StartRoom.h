//
// Created by rob on 10/10/16.
//

#ifndef ITEM_TEST_STARTROOM_H
#define ITEM_TEST_STARTROOM_H


#include "Room.h"

class StartRoom : public Room{
private:
    std::string testing();
public:
    StartRoom(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};


#endif //ITEM_TEST_STARTROOM_H
