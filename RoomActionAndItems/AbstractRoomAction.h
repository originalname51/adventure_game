//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
#define FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H


#include "ActionResults.h"
#include "../ItemsAndActions/Action.h"
#include "../ItemsAndActions/Item.h"
#include "../ItemsAndActions/ItemWrapper.h"
#include "../Command.h"
#include "../ItemsAndActions/ItemTable.h"
#include <vector>

class AbstractRoomAction {
protected:
    ItemTable  *itemList;
    Command    *commands;
public:
    AbstractRoomAction(ItemTable * iTable, Command * command);
    virtual ActionResults * Action();
    virtual ActionResults  * Throw() =0;
    virtual ActionResults   *  Go() =0;
    virtual ActionResults  *  Look()=0;
    ActionResults   Help();
    virtual ActionResults   * Rest()=0;
    virtual ActionResults   * Touch()=0;
    virtual ActionResults   * Pick()=0;
    virtual ActionResults   * Drop()=0;
    virtual ActionResults   *  Use()=0;
    virtual ActionResults  *  Open()=0;
    virtual ActionResults *  Close()=0;




    virtual ~AbstractRoomAction();
};


#endif //FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
