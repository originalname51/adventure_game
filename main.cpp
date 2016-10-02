#include <iostream>
#include <vector>
#include "RoomActionAndItems/RoomActionFiles/AbstractRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/PodiumRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/WaterRoomAction.h"
#include "RoomActionAndItems/Action.h"
#include "Command.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "\nHello back!" << std::endl;


    ItemWrapper it(Item("Test", WATER),
                   PODIUM_ROOM_FLOOR, Action(NORTH));

    std::vector<ItemWrapper> arr;
    ItemWrapper iw(Item("Test", WATER), PODIUM_ROOM_FLOOR, Action(NORTH));
    Command commands(Action(NORTH), it,iw);
    arr.push_back(iw);

    for(int i = 0; i < 2; i++)
    {
        AbstractRoomAction *act;
        if(i == 0)
            act = new PodiumRoomAction(&arr,commands);
        else
            act = new WaterRoomAction();

        std::cout << act->North().getRoom() << "\n";
        free(act);
    }

}