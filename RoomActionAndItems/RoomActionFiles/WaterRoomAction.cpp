//
// Created by rob on 10/1/16.
//

#include "WaterRoomAction.h"
WaterRoomAction::WaterRoomAction(){};
ActionResults WaterRoomAction::Throw(){
    ActionResults returnAction = ActionResults("In Water Room");
    return returnAction;
}
ActionResults WaterRoomAction::North(){
    ActionResults returnAction = ActionResults("In Water Room");
    return returnAction;
}
WaterRoomAction::~WaterRoomAction(){};