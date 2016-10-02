//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_PODIUMROOMACTION_H
#define FINALADVENTUREPROJECT_PODIUMROOMACTION_H

#include <vector>
#include "AbstractRoomAction.h"
#include "../../ItemsAndActions/Action.h"
#include "../../Command.h"
#include <assert.h>

class PodiumRoomAction : public AbstractRoomAction{
public:
    PodiumRoomAction(std::vector<ItemWrapper> *iList, Command commands);
    ActionResults Throw();
    ActionResults North();
    virtual ~PodiumRoomAction();
};

#endif //FINALADVENTUREPROJECT_PODIUMROOMACTION_H
