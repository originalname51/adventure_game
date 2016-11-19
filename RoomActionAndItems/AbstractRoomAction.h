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
    AbstractRoomAction(ItemTable * iTable);
    virtual ActionResults * Action();
    virtual ActionResults  * Throw();
    virtual ActionResults   *  Go() =0;
    virtual ActionResults  *  Look();
    ActionResults * Help();
    virtual ActionResults    * Rest();
    virtual ActionResults    * Touch();
    virtual ActionResults    * Pick();
    virtual ActionResults    * Drop();
    virtual ActionResults    * Use()=0;
    virtual ActionResults    * Open();
    virtual ActionResults    * Close();
    void setCommands(Command * com);




    virtual ~AbstractRoomAction();

    bool hasAToken() const;

    bool itemInRoom(itemType item) const;

    void dropItem(const itemType &item) const;
};


#endif //FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
