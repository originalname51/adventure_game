//
// Created by rob on 10/1/16.
//

#include "Command.h"


Command::Command(actions act, itemType it) :  action(act), mainItem(it), actedOn(NON_EXIST){};
Command::Command(actions act, itemType it, itemType actOn) : action(act), mainItem(it), actedOn(actOn){} ;;
actions  Command::getAction(){ return action; }
itemType Command::getMainItem(){ return mainItem; }
itemType Command::getActedOnItem(){ return actedOn; }
Command::~Command() {};