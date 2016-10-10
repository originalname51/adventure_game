#include <iostream>
#include "Rooms/Room.h"
#include "Rooms/StartRoom.h"

int main() {
    ItemTable table = ItemTable();
    Room *r = new StartRoom("room", &table, true);
    std::cout << "Now printing optional"<< std::endl << r->getDescription()<<std::endl;
    free (r);
    return 0;
}