//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_WATERROOMACTION_H
#define FINALADVENTUREPROJECT_WATERROOMACTION_H

#include "AbstractRoomAction.h"

class WaterRoomAction  : public AbstractRoomAction{
    WaterRoomAction();
    ActionResults Throw();
    ActionResults North();
    virtual ~WaterRoomAction();

};


#endif //FINALADVENTUREPROJECT_WATERROOMACTION_H
