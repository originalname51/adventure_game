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

public:
    ItemTable();
    ItemWrapper*  getValue(itemType const &value) {
        return items.find(value)->second;
        assert(false); //will break if no value assigned.
    }
    ~ItemTable();


};


#endif //FINALADVENTUREPROJECT_ITEMTABLE_H
