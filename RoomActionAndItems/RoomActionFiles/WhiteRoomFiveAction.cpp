//
// Created by rob on 11/20/16.
//

#include "WhiteRoomFiveAction.h"

WhiteRoomFiveAction::WhiteRoomFiveAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

WhiteRoomFiveAction::WhiteRoomFiveAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *WhiteRoomFiveAction::Pick() {
    if(commands->getMainItem() == BOWL) {
        return new ActionResults(CURRENT, "You can't pick it up its stuck to the table!");
    }
    return AbstractRoomAction::Pick();
}

ActionResults *WhiteRoomFiveAction::Look() {
    return AbstractRoomAction::Look();
}

ActionResults *WhiteRoomFiveAction::Use() {
    std::string information;
    if (commands->getMainItem() == PITCHER && commands->getActedOnItem() == BOWL) {
        roomWon = true;
        return new ActionResults (CURRENT, "You pick up the pitcher and start to pour it into the bowl. As you are doing this, the bright bowl starts to project a balanced light, "
                "then sinks into the table. A message below the bowl says ‘Return the crystal to the three keys room. You feel light, and notice the wall behind you has changed to the "
                "room you woke up in.", FIREWORKS);
    } else {
        return AbstractRoomAction::Use();
    }
}

ActionResults *WhiteRoomFiveAction::Go() {

        if(roomWon) {
            return new ActionResults(THREE_KEY_ROOM, "You find yourself in the key room");
        }
        else if(commands->getMainItem() == SOUTH) {
            return new ActionResults(W_ROOM4, "You travel south");
        } else {
            return new ActionResults(CURRENT, "You can't go that way");
        }

}
