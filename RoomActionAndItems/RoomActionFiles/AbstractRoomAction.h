//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
#define FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H


#include "../../ItemsAndActions/ActionResults.h"
#include "../../ItemsAndActions/Action.h"
#include "../../ItemsAndActions/Item.h"
#include "../../ItemsAndActions/ItemWrapper.h"
#include "../../Command.h"
#include "../../ItemsAndActions/ItemTable.h"
#include <vector>

class AbstractRoomAction {
protected:
    ItemTable  *itemList;
    Command    *commands;
public:
    virtual ActionResults Throw() =0;
    virtual ActionResults North() =0;
    virtual ~AbstractRoomAction();
};


#endif //FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
