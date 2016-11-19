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

    ItemWrapper * player = new ItemWrapper(Item("PLAYER", PLAYER), THREE_KEY_ROOM);
    ItemWrapper * nothing= new ItemWrapper(Item("Nothing", NOTHING), HIDDEN);

    items[PLAYER] = player;
    items[NOTHING] = nothing;

    ThreeKeyRoom();
    GreenRoomOne();
    GreenRoomTwo();
    GreenRoomThree();
    GreenRoomFour();
}

void ItemTable::ThreeKeyRoom() {

    ItemWrapper * greenKey = new ItemWrapper(Item("Green Key", GREEN_KEY), THREE_KEY_ROOM);
    ItemWrapper * whiteKey = new ItemWrapper(Item("White Key", WHITE_KEY), THREE_KEY_ROOM);
    ItemWrapper *  blueKey = new ItemWrapper(Item("Blue Key", BLUE_KEY), THREE_KEY_ROOM);

    items[GREEN_KEY] = greenKey;
    items[WHITE_KEY] = whiteKey;
    items[BLUE_KEY]  = blueKey;

}

void ItemTable::GreenRoomOne(){

    ItemWrapper *       foxToken = new ItemWrapper(Item("Fox Token", FOX_TOKEN), G_ROOM1_SIDE1);
    ItemWrapper *      beanToken = new ItemWrapper(Item("Bean Token", BEAN_TOKEN), G_ROOM1_SIDE1);
    ItemWrapper *     gooseToken = new ItemWrapper(Item("Goose Token", GOOSE_TOKEN), G_ROOM1_SIDE1);
    ItemWrapper * gRoomTokenDoor = new ItemWrapper(Item("Token Door", TOKEN_DOOR), HIDDEN);

    items[FOX_TOKEN]   = foxToken;
    items[BEAN_TOKEN]  = beanToken;
    items[GOOSE_TOKEN] = gooseToken;
    items[TOKEN_DOOR]  = gRoomTokenDoor;
}

void ItemTable::GreenRoomTwo() {
    ItemWrapper *      Bucket = new ItemWrapper(Item("Bucket", BLOOD_BUCKET), G_ROOM2_BUCKET);
    ItemWrapper * CleanBucket = new ItemWrapper(Item("Clean Bucket", CLEAN_BUCKET) , HIDDEN);

    items[BLOOD_BUCKET] = Bucket;
    items[CLEAN_BUCKET] = CleanBucket;
}

void ItemTable::GreenRoomThree() {
    ItemWrapper * Basin = new ItemWrapper(Item("Basin", BASIN), G_ROOM3_BASIN);

    items[BASIN] = Basin;
}

void ItemTable::GreenRoomFour() {
    ItemWrapper * Kid = new ItemWrapper(Item("Kid", KID), G_ROOM4_KID);

    items[KID] = Kid;

}

ItemTable::~ItemTable(){
    for(auto i : items){
        free(i.second);
    }
}