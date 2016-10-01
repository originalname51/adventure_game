//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ITEMWRAPPER_H
#define FINALADVENTUREPROJECT_ITEMWRAPPER_H
#include "Item.h"


class ItemWrapper {
private:
    const Item  classItem;
    std::string location;
public:
    ItemWrapper(Item item, std::string l);
    std::string getLocation();
    void setLocation(std::string l);
};


#endif //FINALADVENTUREPROJECT_ITEMWRAPPER_H
