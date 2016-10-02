//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ITEMWRAPPER_H
#define FINALADVENTUREPROJECT_ITEMWRAPPER_H
#include "Item.h"
#include "Action.h"

enum item_location { PODIUM_ROOM_FLOOR, PODIUM_ROOM, WATER_ROOM_FLOOR, WATER_ROOM_UNDERWATER };

class ItemWrapper {
private:
    const Item    classItem;
    item_location location;
    const Action defaultAction;
public:
    ItemWrapper(Item item, item_location l, Action d);
    item_location getLocation();
    void setLocation(item_location l);

};


#endif //FINALADVENTUREPROJECT_ITEMWRAPPER_H
