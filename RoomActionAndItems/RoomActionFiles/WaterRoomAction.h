//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_WATERROOMACTION_H
#define FINALADVENTUREPROJECT_WATERROOMACTION_H

#include "../AbstractRoomAction.h"

class WaterRoomAction  : public AbstractRoomAction{
public:
    WaterRoomAction();
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
    virtual ~WaterRoomAction();

};


#endif //FINALADVENTUREPROJECT_WATERROOMACTION_H
