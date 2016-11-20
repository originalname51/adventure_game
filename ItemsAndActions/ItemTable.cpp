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
    BlueRoomOne();
    BlueRoomTwo();
    BlueRoomThree();
    BlueRoomFour();
    WhiteRoomOne();

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

void ItemTable::WhiteRoomOne() {
    //    DISCUS, POWER_CRYSTAL, TORCH, LIGHT_PILLAR,

    ItemWrapper * Discus         = new ItemWrapper(Item("Disc", DISCUS), W_ROOM1);
    ItemWrapper * PowerCrystal   = new ItemWrapper(Item("PowerCrystal", POWER_CRYSTAL), W_ROOM1);
    ItemWrapper * Torch          = new ItemWrapper(Item("Torch", TORCH), W_ROOM1);
    ItemWrapper * LPiller        = new ItemWrapper(Item("Light Pillar", LIGHT_PILLAR), W_ROOM1);
    ItemWrapper * Ladder         = new ItemWrapper(Item("Ladder", LADDER), HIDDEN);

    items[DISCUS] = Discus;
    items[POWER_CRYSTAL] = PowerCrystal;
    items[TORCH] = Torch;
    items[LIGHT_PILLAR] = LPiller;
    items[LADDER] = Ladder;
}

void ItemTable::BlueRoomOne() {
    ItemWrapper * Torch = new ItemWrapper(Item("A Torch", TORCH), HIDDEN);
    items[TORCH] = Torch;
}

void ItemTable::BlueRoomTwo() {

    ItemWrapper * BabbleFish    = new ItemWrapper(Item("BabbleFish", FISH), B_ROOM2);
    ItemWrapper * Ceiling       = new ItemWrapper(Item("Cieling", CEILING), B_ROOM2);
    ItemWrapper * Glpyhs        = new ItemWrapper(Item("Glyphs", GLYPHS), B_ROOM2);

    items[FISH] = BabbleFish;
    items[CEILING] = Ceiling;
    items[GLYPHS] = Glpyhs;
}

void ItemTable::BlueRoomThree() {

    ItemWrapper * Pipes         = new ItemWrapper(Item("PIPES", PIPE), B_ROOM3);
    ItemWrapper * Ball          = new ItemWrapper(Item("BALL", BALL),  B_ROOM3 );

    items[PIPE] = Pipes;
    items[BALL] = Ball;

}

void ItemTable::BlueRoomFour() {

    ItemWrapper *        Rope = new ItemWrapper(Item("Rope", ROPE), B_ROOM4);
    ItemWrapper * WhitePillar = new ItemWrapper(Item("White Pillar", WHITE_PILLAR), B_ROOM4);
    ItemWrapper * BlackPillar = new ItemWrapper(Item("Black Pillar", BLACK_PILLAR), B_ROOM4);

    items[ROPE] = Rope;
    items[WHITE_PILLAR] = WhitePillar;
    items[BLACK_PILLAR] = BlackPillar;

}

ItemTable::~ItemTable(){
    for(auto i : items){
        free(i.second);
    }
}