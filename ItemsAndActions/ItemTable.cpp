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

    GreenRoomOne();

    ItemWrapper *      Player = new ItemWrapper(Item("PLAYER", PLAYER), G_ROOM1_SIDE1);

}
void ItemTable::GreenRoomOne(){

    ItemWrapper *       foxToken = new ItemWrapper(Item("Fox Token", FOX_TOKEN), G_ROOM1_SIDE1);
    ItemWrapper *      beanToken = new ItemWrapper(Item("Bean Token", BEAN_TOKEN), G_ROOM1_SIDE1);
    ItemWrapper *     gooseToken = new ItemWrapper(Item("Goose Token", GOOSE_TOKEN), G_ROOM1_SIDE1);
    ItemWrapper * gRoomTokenDoor = new ItemWrapper(Item("Token Door", TOKEN_DOOR), G_ROOM1_TOKEN_DOOR);

    items[FOX_TOKEN]   = foxToken;
    items[BEAN_TOKEN]  = beanToken;
    items[GOOSE_TOKEN] = gooseToken;
    items[TOKEN_DOOR]  = gRoomTokenDoor;
}



ItemTable::~ItemTable(){
    for(auto i : items){
        free(i.second);
    }
}