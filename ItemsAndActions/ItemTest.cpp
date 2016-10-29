#include <iostream>
#include "ItemTable.h"
#include "ItemTest.h"


int main() {

    ItemTest makeTest = ItemTest();
    makeTest.itemClassTest();
    std::cout << "Basic Item Class Unit Test Passed." << "\n\n";
    makeTest.itemWrapperTest();
    std::cout << "ItemWrapper Unit Test Passed." << "\n\n";
    makeTest.itemTableTest();
    std::cout << "Item Table Unit Test Passed." << "\n\n";

    return 0;
}

void ItemTest::itemClassTest() {
    Item water = Item("Water", WATER);
    assert (water.getDescription() == "Water");
    assert (water.getItemType() == WATER);
    assert (water.getItemType() != SHIH_TZU);
    water.getItemType();
}
void ItemTest::itemWrapperTest(){

    Item water   = Item("Water", WATER);
    Item shihTzu = Item("Shih Tzu", SHIH_TZU);

    ItemWrapper waterWrapper   = ItemWrapper(water, WATER_ROOM_UNDERWATER, GO);
   // ItemWrapper shihTzuWrapper = ItemWrapper(shihTzu, PODIUM_ROOM_FLOOR);

    assert(waterWrapper.getDefaultAction().getAction() == GO);
    assert(waterWrapper.getLocation() == WATER_ROOM_UNDERWATER);
    waterWrapper.setLocation(PODIUM_ROOM);
    assert(waterWrapper.getLocation() == PODIUM_ROOM);

 //   assert(shihTzuWrapper.getDefaultAction().getAction() == NOTHING);
 //   assert(shihTzuWrapper.getLocation() == PODIUM_ROOM_FLOOR);
  //  shihTzuWrapper.setLocation(PODIUM_ROOM);
  //  assert(shihTzuWrapper.getLocation() == PODIUM_ROOM);
}
void ItemTest::itemTableTest(){

    ItemTable *allItems = new ItemTable();
    allItems->getValue(WATER)->setLocation(PODIUM_ROOM);
    assert(allItems->getValue(WATER)->getLocation() == PODIUM_ROOM);
    assert(allItems->getValue(SHIH_TZU)->getLocation() == WATER_ROOM_UNDERWATER);
    allItems->getValue(WATER)->setLocation(GO_NORTH);
    assert(allItems->getValue(WATER)->getLocation() == GO_NORTH);
}

ItemTest::ItemTest(){};

