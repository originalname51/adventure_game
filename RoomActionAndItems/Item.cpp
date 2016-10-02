//
// Created by rob on 10/1/16.
//

#include "Item.h"
Item::Item(std::string d, itemType t) : description(d), item(t) {};
std::string Item::getDescription(){return description;};