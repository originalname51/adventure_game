//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_GREENROOMFOUR_H
#define ITEM_TEST_GREENROOMFOUR_H


#include "Room.h"

class GreenRoomFour : public Room{
private:
    std::string testing();
public:
    GreenRoomFour(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};



#endif //ITEM_TEST_GREENROOMFOUR_H
