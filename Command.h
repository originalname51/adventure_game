//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_COMMAND_H
#define FINALADVENTUREPROJECT_COMMAND_H


#include "RoomActionAndItems/Action.h"
#include "RoomActionAndItems/Item.h"
#include "RoomActionAndItems/ItemWrapper.h"

class Command {
private:
    const Action action;
    const ItemWrapper actedOn;
    const ItemWrapper mainItem;
public:
//    Command(Action act, ItemWrapper it);
    Command(Action act, ItemWrapper it, ItemWrapper actOn);

};
#endif //FINALADVENTUREPROJECT_COMMAND_H
