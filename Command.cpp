//
// Created by rob on 10/1/16.
//

#include "Command.h"
//Command::Command(Action act, ItemWrapper it) : action(act), mainItem(it), actedOn(Item(),PODIUM_ROOM_FLOOR){};
Command::Command(Action act, ItemWrapper it,ItemWrapper actOn) : action(act), mainItem(it), actedOn(actOn){} ;
