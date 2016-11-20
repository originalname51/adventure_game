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
    SHIH_TZU, NON_EXIST,

    //Items in "Green Room One"
    FOX_TOKEN, BEAN_TOKEN, G_BOAT, GOOSE_TOKEN, TOKEN_DOOR,

    //Three Key Room Items
    GREEN_KEY, WHITE_KEY, BLUE_KEY,

    //GREEN Hospital room
    BLOOD_BUCKET, CLEAN_BUCKET,

    //Basin Room and //Kid-key room
    WATER, BASIN,

    //Kid-key room
    KID,

    //BLUE - Misty Room
    GLYPHS, FISH, CEILING,

    //BLUE - Ice Room
    BALL, PIPE,

    //BLUE TORCH
    TORCH,

    //BLUE - Dark Room
    TABLET, STATUE, BOX,

    //BLUE - Mirror Room
    ROPE, WHITE_PILLAR, BLACK_PILLAR,

    //WHITE - Room 2
    NORTH_WALL, EAST_WALL, WEST_WALL,
    
    //WHITE - PILLAR room
    DISCUS, POWER_CRYSTAL, LIGHT_PILLAR, LADDER,

    //WHITE - Table Room
    PITCHER, BOWL, LIGHT

};

class Item {
private:
    const std::string name;
    const itemType item;
public:
    Item(std::string d, itemType type);
    std::string getName();
    itemType getItemType();
};


#endif //FINALADVENTUREPROJECT_ITEM_H
