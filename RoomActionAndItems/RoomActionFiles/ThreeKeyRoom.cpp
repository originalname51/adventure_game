//
// Created by rob on 10/29/16.
//

#include "ThreeKeyRoom.h"

ThreeKeyRoom::ThreeKeyRoom(ItemTable *iList, Command *commands) : AbstractRoomAction(iList,commands) {}

ActionResults  *   ThreeKeyRoom::Throw(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *      ThreeKeyRoom::Go(){

    itemType direction = commands->getMainItem();

    switch(direction) {
        case WEST:
            if (isDoorOpen(GREEN_KEY)) {
                return new ActionResults(G_ROOM1_SIDE1, "You move into the Green Room.");
            }
            else {return new ActionResults(CURRENT,"You can not move forward without a key.");
            }
        case EAST:
            if (isDoorOpen(WHITE_KEY)) {
                return new ActionResults(G_ROOM1_SIDE1, "You move into the White Room.");
            }
            else {return new ActionResults(CURRENT,"You can not move forward without a key.");
            }
        case NORTH:
            if (isDoorOpen(BLUE_KEY)) {
                return new ActionResults(G_ROOM1_SIDE1, "You move into the Blue Room.");
            }
            else {return new ActionResults(CURRENT,"You can not move forward without a key.");
            }
        default:
            return new ActionResults(CURRENT, "Can't move in this direction");
    }

}

bool ThreeKeyRoom::isDoorOpen(const itemType &key) const {
    return itemList->getValue(key)->getLocation() == BACKPACK;
}

ActionResults  *    ThreeKeyRoom::Look(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *    ThreeKeyRoom::Rest(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *   ThreeKeyRoom::Touch(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *    ThreeKeyRoom::Pick(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *    ThreeKeyRoom::Drop(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *     ThreeKeyRoom::Use(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *    ThreeKeyRoom::Open(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *   ThreeKeyRoom::Close(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
//ActionResults  * ThreeKeyRoom::Nothing();
