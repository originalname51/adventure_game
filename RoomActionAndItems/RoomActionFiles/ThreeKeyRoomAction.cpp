//
// Created by rob on 10/29/16.
//

#include "ThreeKeyRoomAction.h"

ThreeKeyRoomAction::ThreeKeyRoomAction(ItemTable *iList, Command *commands) : AbstractRoomAction(iList,commands) {}

ThreeKeyRoomAction::ThreeKeyRoomAction(ItemTable *iList) : AbstractRoomAction(iList) {}

ActionResults  *   ThreeKeyRoomAction::Throw(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *      ThreeKeyRoomAction::Go(){

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

bool ThreeKeyRoomAction::isDoorOpen(const itemType &key) const {
    return itemList->getValue(key)->getLocation() == BACKPACK;
}

ActionResults  *    ThreeKeyRoomAction::Look(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *    ThreeKeyRoomAction::Rest(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *   ThreeKeyRoomAction::Touch(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *    ThreeKeyRoomAction::Pick(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *    ThreeKeyRoomAction::Drop(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *     ThreeKeyRoomAction::Use(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *    ThreeKeyRoomAction::Open(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
ActionResults  *   ThreeKeyRoomAction::Close(){
    return new ActionResults(CURRENT,"Not implemented yet");
}
//ActionResults  * ThreeKeyRoom::Nothing();
