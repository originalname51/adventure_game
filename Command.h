//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_COMMAND_H
#define FINALADVENTUREPROJECT_COMMAND_H


#include "ItemsAndActions/Action.h"
#include "ItemsAndActions/Item.h"
#include "ItemsAndActions/ItemWrapper.h"

class Command {
private:
    const Action action;
    const itemType actedOn;
    const itemType mainItem;
public:
    Command(actions act, itemType it);
    Command(actions act, itemType it, itemType actOn);

};
#endif //FINALADVENTUREPROJECT_COMMAND_H
