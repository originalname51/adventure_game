//
// Created by rob on 10/29/16.
//

#ifndef ITEM_TEST_GREENROOMONE_H
#define ITEM_TEST_GREENROOMONE_H


#include "Room.h"

class GreenRoomOne : public Room {

    private:
    std::string testing();
    public:
    GreenRoomOne(std::string, ItemTable *iList, bool f);
    std::string getDescription(bool longform);
};



#endif //ITEM_TEST_GREENROOMONE_H
