//
// Created by rob on 10/2/16.
//

#include "ItemTable.h"
ItemTable::ItemTable(){
    populateMap();



}
ItemWrapper*  ItemTable::getValue(itemType const &value) {
return items.find(value)->second;
assert(false); //will break if no value assigned.
}

void ItemTable::populateMap(){

    /* NORTH, WATER, SHIH_TZU, NON_EXIST */
    ItemWrapper *north = new ItemWrapper(Item("North", NORTH),
                                         GO_NORTH);

    ItemWrapper *water = new ItemWrapper(Item("Water", WATER),
                                      PODIUM_ROOM_FLOOR, Action(THROW));

    ItemWrapper *shih_tzu = new ItemWrapper(Item("SHIH_TZU", SHIH_TZU),
                                       WATER_ROOM_UNDERWATER, Action(THROW));

    /* NORTH, WATER, SHIH_TZU, NON_EXIST */
    items[NORTH]     = north;
    items[WATER]     = water;
    items[SHIH_TZU]  = shih_tzu;

}

ItemTable::~ItemTable(){
    for(auto i : items){
        free(i.second);
    }
}