//
// Created by rob on 10/1/16.
//

#include "PodiumRoomAction.h"
ActionResults PodiumRoomAction::Throw(){
    ActionResults returnAction = ActionResults("In Podim Room");
    return returnAction;
}
ActionResults PodiumRoomAction::North(){
    ActionResults returnAction = ActionResults("In Podium Room");
    return returnAction;
}
PodiumRoomAction::PodiumRoomAction() {};
PodiumRoomAction::~PodiumRoomAction() {};