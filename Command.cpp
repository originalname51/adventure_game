//
// Created by rob on 10/1/16.
//

#include "Command.h"
/*
ItemWrapper
Command::Command(Action act, ItemWrapper it) : action(act), mainItem(it),
                                               actedOn((("hi,",WATER), PODIUM_ROOM_FLOOR) NORTH) {};*/
Command::Command(Action act, ItemWrapper it,ItemWrapper actOn) : action(act), mainItem(it), actedOn(actOn){} ;
