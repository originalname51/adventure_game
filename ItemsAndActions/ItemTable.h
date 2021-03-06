//
// Created by rob on 10/2/16.
//

#ifndef FINALADVENTUREPROJECT_ITEMTABLE_H
#define FINALADVENTUREPROJECT_ITEMTABLE_H


#include <map>
#include <assert.h>
#include "Item.h"
#include "ItemWrapper.h"

class ItemTable {
private:
    typedef std::map<itemType , ItemWrapper*> ItemList;
    ItemList items;
    static const ItemTable gameItems;
    void populateMap();
    void GreenRoomOne();
    void GreenRoomTwo();
    void GreenRoomThree();
    void GreenRoomFour();
    void ThreeKeyRoom();
    void WhiteRoomOne();
    void WhiteRoomTwo();
    void WhiteRoomThree();
    void WhiteRoomFour();
    void WhiteRoomFive();
    void BlueRoomOne();
    void BlueRoomTwo();
    void BlueRoomThree();
    void BlueRoomFour();
    void BlueRoomFive();

public:
    ItemTable();
    ItemWrapper*  getValue(itemType const &value);
    ~ItemTable();



};


#endif //FINALADVENTUREPROJECT_ITEMTABLE_H
