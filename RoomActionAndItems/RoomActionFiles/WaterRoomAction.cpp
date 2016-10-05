//
// Created by rob on 10/1/16.
//

#include "WaterRoomAction.h"
WaterRoomAction::WaterRoomAction(){};
ActionResults WaterRoomAction::Throw(){

    room r  = CURRENT;
    ActionResults returnAction = ActionResults(r, "In Podium Room");
    return returnAction;
}
ActionResults WaterRoomAction::North(){

    room r  = CURRENT;
    ActionResults returnAction = ActionResults(r, "In Podium Room");
    return returnAction;
}
WaterRoomAction::~WaterRoomAction(){};