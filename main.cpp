#include <iostream>
#include <vector>
#include <map>
#include "RoomActionAndItems/RoomActionFiles/AbstractRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/PodiumRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/WaterRoomAction.h"
#include "ItemsAndActions/Action.h"
#include "Command.h"
#include "ItemsAndActions/ItemTable.h"

int main() {

    ItemTable *allItems = new ItemTable();

    allItems->getValue(WATER)->setLocation(PODIUM_ROOM);
    assert(allItems->getValue(WATER)->getLocation() == PODIUM_ROOM);
    assert(allItems->getValue(SHIH_TZU)->getLocation() == WATER_ROOM_UNDERWATER);

    Command commands(GO, NORTH);
return 0;
}