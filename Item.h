//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ITEM_H
#define FINALADVENTUREPROJECT_ITEM_H
#include <iostream>


class Item {
private:
    const std::string description;
    const std::string location;
public:
    Item(std::string d, std::string l) : description(d), location(l) {};
    std::string getDescription(){return description;};
    std::string getLocation(){return location;};
};


#endif //FINALADVENTUREPROJECT_ITEM_H
