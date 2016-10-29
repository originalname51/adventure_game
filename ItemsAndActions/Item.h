//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ITEM_H
#define FINALADVENTUREPROJECT_ITEM_H
#include <iostream>

enum itemType {PLAYER, NORTH, SOUTH, EAST, WEST,
    WATER, SHIH_TZU, NON_EXIST, FOX_TOKEN,BEAN_TOKEN,G_BOAT,GOOSE_TOKEN,TOKEN_DOOR, NOTHING};
class Item {
private:
    const std::string description;
    const itemType item;
public:
    Item(std::string d, itemType type);
    std::string getDescription();
    itemType getItemType();
};


#endif //FINALADVENTUREPROJECT_ITEM_H
