//
// Created by rob on 10/1/16.
//

#include "ItemWrapper.h"
ItemWrapper::ItemWrapper(Item item, std::string l) : classItem(item), location(l){};
std::string ItemWrapper::getLocation(){return location;}
void ItemWrapper::setLocation(std::string l){location = l;}
