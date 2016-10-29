//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ITEMWRAPPER_H
#define FINALADVENTUREPROJECT_ITEMWRAPPER_H
#include "Item.h"
#include "Action.h"

enum itemLocation {

    THREE_KEY_ROOM,

    PODIUM_ROOM, WATER_ROOM_UNDERWATER, GO_NORTH,

    G_ROOM1_SIDE1, G_ROOM1_SIDE2, G_ROOM1_TOKEN_DOOR,

    BACKPACK,CURRENT, KEY_ROOM };



enum itemState { DEFAULT,
    SPECIAL, CHANGED, ON};

class ItemWrapper {

private:
    Item   classItem;
    itemLocation location;
    Action defaultAction;
    itemState    state;
    std::string  itemName;

public:
    void setItemName(std::string);
    std::string getItemName();
    ItemWrapper(Item item, itemLocation l);
    ItemWrapper(Item item, itemLocation l, Action d);
    itemLocation getLocation();
    void setLocation(itemLocation l);
    Action  getDefaultAction();
    itemState getState();
    void setState(itemState s);
};


#endif //FINALADVENTUREPROJECT_ITEMWRAPPER_H
