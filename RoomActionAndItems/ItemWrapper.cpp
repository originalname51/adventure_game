//
// Created by rob on 10/1/16.
//

#include "ItemWrapper.h"
ItemWrapper::ItemWrapper(Item item, item_location l, Action d) : classItem(item), location(l)
, defaultAction(d){};
item_location ItemWrapper::getLocation(){return location;}
void ItemWrapper::setLocation(item_location l){location = l;}
