//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ITEMWRAPPER_H
#define FINALADVENTUREPROJECT_ITEMWRAPPER_H
#include "Item.h"
#include "Action.h"

enum itemLocation { PODIUM_ROOM_FLOOR,
    PODIUM_ROOM, WATER_ROOM_UNDERWATER, GO_NORTH,
    G_ROOM1_SIDE1, G_ROOM1_SIDE2,G_ROOM1_TOKEN_DOOR, BACKPACK };

enum itemType {PLAYER, NORTH, SOUTH, EAST, WEST,
    WATER, SHIH_TZU, NON_EXIST, FOX_TOKEN,BEAN_TOKEN,GOOSE_TOKEN,TOKEN_DOOR};

enum itemState { DEFAULT,
    SPECIAL, CHANGED, ON};

class ItemWrapper {

private:
    const Item   classItem;
    itemLocation location;
    const Action defaultAction;
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
