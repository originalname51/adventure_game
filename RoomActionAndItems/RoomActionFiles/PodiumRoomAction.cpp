//
// Created by rob on 10/1/16.
//

#include "PodiumRoomAction.h"
ActionResults PodiumRoomAction::Throw(){
    room START_ROOM  = CURRENT;
    ActionResults returnAction = ActionResults(START_ROOM, "In Podium Room");
    return returnAction;
}
ActionResults PodiumRoomAction::North(){
    room START_ROOM  = CURRENT;
    ActionResults returnAction = ActionResults(START_ROOM, "In Podium Room");
    return returnAction;
}

PodiumRoomAction::PodiumRoomAction(ItemTable *iList, Command *c) {
        itemList = iList;
        commands = c;
};
PodiumRoomAction::~PodiumRoomAction() {};