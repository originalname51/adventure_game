//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ITEM_H
#define FINALADVENTUREPROJECT_ITEM_H
#include <iostream>

enum itemType {
    //Basic Types of "Items" needed.
    PLAYER, NORTH, SOUTH, EAST, WEST, NOTHING,

    //Items not used for anything currently.
    WATER, SHIH_TZU, NON_EXIST,

    //Items in "Green Room One"
    FOX_TOKEN, BEAN_TOKEN, G_BOAT, GOOSE_TOKEN, TOKEN_DOOR,

    //Three Key Room Items
    GREEN_KEY, WHITE_KEY, BLUE_KEY

};

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
