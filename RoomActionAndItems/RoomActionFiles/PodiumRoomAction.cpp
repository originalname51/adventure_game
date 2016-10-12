//
// Created by rob on 10/1/16.
//

#include "PodiumRoomAction.h"
PodiumRoomAction::PodiumRoomAction(ItemTable *iList, Command *commands) : items(iList), command(commands){}

ActionResults  PodiumRoomAction::Throw(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults     PodiumRoomAction::Go(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults    PodiumRoomAction::Look(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults    PodiumRoomAction::Rest(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults   PodiumRoomAction::Touch(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults    PodiumRoomAction::Pick(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults    PodiumRoomAction::Drop(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults     PodiumRoomAction::Use(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults    PodiumRoomAction::Open(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
ActionResults   PodiumRoomAction::Close(){
    std::string filler="filler";
    return ActionResults(CURRENT, filler);
}
PodiumRoomAction::~PodiumRoomAction() {};