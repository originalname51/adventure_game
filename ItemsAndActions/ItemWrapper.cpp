//
// Created by rob on 10/1/16.
//

#include "ItemWrapper.h"

ItemWrapper::ItemWrapper(Item item, itemLocation l) : classItem(item), location(l),
defaultAction(Action(NOTHING)), state(DEFAULT){}

ItemWrapper::ItemWrapper(Item item, itemLocation l, Action d) : classItem(item), location(l)
, defaultAction(d), state(DEFAULT){}

itemLocation ItemWrapper::getLocation(){return location;}

void ItemWrapper::setLocation(itemLocation l){location = l;}

Action ItemWrapper::getDefaultAction(){return defaultAction;}

itemState ItemWrapper::getState(){return state;}

void ItemWrapper::setState(itemState s){state =s;}

void ItemWrapper::setItemName(std::string item) {
    itemName = item;
}

std::string ItemWrapper::getItemName() {
    return itemName;
}
