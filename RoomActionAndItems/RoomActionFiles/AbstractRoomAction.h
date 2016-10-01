//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
#define FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H


#include "../ActionResults.h"

class AbstractRoomAction {
public:
    virtual ActionResults Throw() =0;
    virtual ActionResults North() =0;
    virtual ~AbstractRoomAction() =0;
};


#endif //FINALADVENTUREPROJECT_ABSTRACTROOMACTION_H
