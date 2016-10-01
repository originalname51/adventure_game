//
// Created by rob on 10/1/16.
//

#include "Item.h"
Item::Item(std::string d, std::string l) : description(d), location(l) {};
std::string Item::getDescription(){return description;};
std::string Item::getLocation(){return location;};