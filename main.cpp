#include <iostream>
#include "Room.h"

int main() {

    Room r = Room("room");
    std::cout << r.getDefault() << std::endl;
    std::cout << "Now printing optional" << std::endl;
    std::cout << r.getUpdated() << std::endl;
    return 0;
}