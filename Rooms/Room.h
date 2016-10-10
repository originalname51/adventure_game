//
// Created by rob on 10/4/16.
//

#ifndef ITEM_TEST_ROOM_H
#define ITEM_TEST_ROOM_H
#include <iostream>
#include <assert.h>
#include <fstream>
#include "configuration.h"
#include "../ItemsAndActions/ItemTable.h"

enum description {
    ROOM_STATE_0,ROOM_STATE_1, ROOM_STATE_2
};
enum room {START_ROOM, END_ROOM, CURRENT};

class Room {
protected:
    std::string defaultDescription;
    std::string updatedDescription;
    std::string getDefault();
    std::string getUpdated();
    std::string roomName;
    ItemTable * table;
    bool showLongDescription;
    void parseData();
public:
    Room();
    Room(std::string, ItemTable *iList, bool f);
    virtual std::string getDescription()=0;
};


#endif //ITEM_TEST_ROOM_H
