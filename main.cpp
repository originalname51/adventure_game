#include <iostream>
#include "RoomActionAndItems/RoomActionFiles/AbstractRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/PodiumRoomAction.h"
#include "RoomActionAndItems/RoomActionFiles/WaterRoomAction.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "\nHello back!" << std::endl;
    for(int i = 0; i < 2; i++)
    {
        AbstractRoomAction *act;
        if(i == 0)
            act = new PodiumRoomAction();
        else
            act = new WaterRoomAction();

        std::cout << act->North().getRoom() << "\n";
        free(act);
    }
}