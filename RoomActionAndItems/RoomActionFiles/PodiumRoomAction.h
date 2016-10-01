//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_PODIUMROOMACTION_H
#define FINALADVENTUREPROJECT_PODIUMROOMACTION_H
#include "AbstractRoomAction.h"

class PodiumRoomAction : public AbstractRoomAction{
    ActionResults Throw();
    ActionResults North();
    virtual ~PodiumRoomAction();
};


#endif //FINALADVENTUREPROJECT_PODIUMROOMACTION_H
