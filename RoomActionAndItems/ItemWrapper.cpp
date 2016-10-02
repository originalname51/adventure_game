//
// Created by rob on 10/1/16.
//

#include "ItemWrapper.h"
ItemWrapper::ItemWrapper(Item item, itemLocation l, Action d) : classItem(item), location(l)
, defaultAction(d){};
itemLocation ItemWrapper::getLocation(){return location;}
void ItemWrapper::setLocation(itemLocation l){location = l;}
Action ItemWrapper::getDefaultAction(){return defaultAction;}