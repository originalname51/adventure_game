//
// Created by rob on 10/4/16.
//

#include <assert.h>
#include "Room.h"

std::string Room::lookup(room r) {
    switch(r) {
        case START_ROOM:
            return "StartRoom";
        case END_ROOM:
            return "EndRoom";
        default:
            assert(false); //break program if no room.
    }
}
