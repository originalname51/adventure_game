//
// Created by rob on 10/2/16.
//

#include "ItemTable.h"
ItemTable::ItemTable(){
    populateMap();



}

void ItemTable::populateMap(){
    ItemWrapper *it = new ItemWrapper(Item("Water", WATER),
                                      PODIUM_ROOM_FLOOR, Action(THROW));
    ItemWrapper *itt = new ItemWrapper(Item("SHIH_TZU", SHIH_TZU),
                                       WATER_ROOM_UNDERWATER, Action(THROW));


    items[WATER]     = it;
    items[SHIH_TZU]  = itt;
}

ItemTable::~ItemTable(){
    for(auto i : items){
        free(i.second);
    }
}