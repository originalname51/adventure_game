//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
#define FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H


#include "../ActionResults.h"
#include "../Action.h"
#include "../Item.h"
#include "../ItemWrapper.h"
#include "../../Command.h"
#include <vector>

class AbstractRoomAction {
protected:
    const int    MIN_ACTIONS = 2;
    const int    MAX_ACTIONS = 3;
    std::vector<ItemWrapper> *itemList;
    Command                  *commands;
public:
    virtual ActionResults Throw() =0;
    virtual ActionResults North() =0;
    virtual ~AbstractRoomAction();
};


#endif //FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
