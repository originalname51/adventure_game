//
// Created by rob on 10/1/16.
//

#include "Item.h"
Item::Item(std::string d, itemType t) : name(d), item(t) {};
std::string Item::getName(){return name;};
itemType Item::getItemType(){
    return item;
};
