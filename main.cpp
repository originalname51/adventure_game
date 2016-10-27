#include <iostream>
#include "Rooms/Room.h"
#include "Rooms/StartRoom.h"
#include "Rooms/KeyRoom.h"
#include "parser.h"

int main() {

    ItemTable table = ItemTable();
    Room *r = new KeyRoom("keyroom", &table, false);
    std::cout << std::endl << r->getDescription()<<std::endl;

    parser commandObj;
    std::string commandIn("Use Scales");

    std::cout << "Command: " << commandIn << std::endl;
    commandObj.setCommandIn(commandObj, commandIn);

    //std::cout << "Command recorded: " << commandObj.cmd << std::endl;
    free (r);
    return 0;
}