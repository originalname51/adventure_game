//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_PODIUMROOMACTION_H
#define FINALADVENTUREPROJECT_PODIUMROOMACTION_H

#include <vector>
#include "../AbstractRoomAction.h"
#include "../../ItemsAndActions/Action.h"
#include "../../Command.h"
#include "../../ItemsAndActions/ItemTest.h"
#include <assert.h>

class PodiumRoomAction : public AbstractRoomAction{
private:
    ItemTable * items;
    Command  * command;
public:
    PodiumRoomAction(ItemTable *iList, Command *commands);
    ActionResults  Throw() ;
    ActionResults     Go() ;
    ActionResults    Look();
    ActionResults    Rest();
    ActionResults   Touch();
    ActionResults    Pick();
    ActionResults    Drop();
    ActionResults     Use();
    ActionResults    Open();
    ActionResults   Close();
    virtual ~PodiumRoomAction();
};

#endif //FINALADVENTUREPROJECT_PODIUMROOMACTION_H
