//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ITEMWRAPPER_H
#define FINALADVENTUREPROJECT_ITEMWRAPPER_H
#include "Item.h"
#include "Action.h"

enum itemLocation {

    THREE_KEY_ROOM, HIDDEN,

    PODIUM_ROOM, WATER_ROOM_UNDERWATER, GO_NORTH,

    //Green Rooms
    G_ROOM1_SIDE1, G_ROOM1_SIDE2, G_ROOM2_BUCKET, G_ROOM3_BASIN, G_ROOM4_KID,

    //White Rooms
    W_ROOM1, W_ROOM2,

    //Blue Rooms
    B_ROOM1, B_ROOM2, B_ROOM3, B_ROOM4,

    BACKPACK, CURRENT };



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
    Item getItem();
};


#endif //FINALADVENTUREPROJECT_ITEMWRAPPER_H
