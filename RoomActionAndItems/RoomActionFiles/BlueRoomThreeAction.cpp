//
// Created by rob on 11/19/16.
//

#include "BlueRoomThreeAction.h"

BlueRoomThreeAction::BlueRoomThreeAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}

BlueRoomThreeAction::BlueRoomThreeAction(ItemTable *iTable) : AbstractRoomAction(iTable) {}

ActionResults *BlueRoomThreeAction::Use() {
    if ((commands->getMainItem() == BALL && commands->getActedOnItem() == PIPE)
            || (commands->getMainItem() == PIPE && commands->getActedOnItem() == BALL)) {
        itemList->getValue(BALL)->setLocation(HIDDEN);
        itemList->getValue(PIPE)->setLocation(WON);
        return new ActionResults(CURRENT, "The ball disappears into the pipes and you here a lot of clanking and finally a click as the door unlocks to the north.");
    } else {
        return AbstractRoomAction::Use();
    }
}

ActionResults * BlueRoomThreeAction::Rest() {
    return new ActionResults(CURRENT, "You look for a place to sit down that won't result in frostbite. You find a patch of \"warm-ish\" ice and sit for a while. Fun stuff.");
}

ActionResults * BlueRoomThreeAction::Go() {

    if (commands->getMainItem() == NORTH) {
        if(itemList->getValue(BALL)->getLocation() == HIDDEN || itemList->getValue(BALL)->getLocation() == WON) {
            return new ActionResults(B_ROOM4, "Shaking your head at the ornate nature of the lock, you go north.");
        } else {
            return new ActionResults(CURRENT, "The door is locked in what looks like a mechanical way, with a series of pipes "
                    "anchoring it to the walls.");
        }
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(B_ROOM2, "Back to the misty fish room eh? You head south.");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south...");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south...");
    }
    return new ActionResults(CURRENT,"You can't go there.");

}

ActionResults * BlueRoomThreeAction::Pick() {
    if(commands->getMainItem() == BALL && itemList->getValue(BALL)->getLocation() == B_ROOM3){
        return new ActionResults(CURRENT, "You pick up the weighty steel ball. It is no fanciful feat, but you feel accomplished none the less.");
    } else if(commands->getMainItem() == PIPE){
        return new ActionResults(CURRENT, "You attempt to pry loose a section of pipe, but the metal is so cold that you can only hold on for a second. No pipe shall you hold today.");
    } else {
        return AbstractRoomAction::Pick();
    }
}

ActionResults * BlueRoomThreeAction::Look() {
    if (commands->getMainItem() == PIPE) {
        return new ActionResults(CURRENT, "The pipes appear to be some complex, interconnected mechanism, each about 3 inches in diameter.");
    } else if(commands->getMainItem() == BALL){
        return new ActionResults(CURRENT, "The ball is between 2 to 3 inches in diameter. Looks like it might fit through those pipes.");
    } else {
        return AbstractRoomAction::Look();
    }
}

ActionResults *BlueRoomThreeAction::Throw() {
    if(commands->getMainItem() == BALL && itemList->getValue(BALL)->getLocation() == BACKPACK){
        return new ActionResults(CURRENT, "You throw the ball across the room. It clanks around the icy metal pipes for a bit, then rolls to a rest on the frozen floor.");
    } else {
        return AbstractRoomAction::Throw();
    }
}

ActionResults *BlueRoomThreeAction::Drop() {
    if(commands->getMainItem() == BALL && itemList->getValue(BALL)->getLocation() == BACKPACK) {
        return new ActionResults(CURRENT, "You really dropped the ball this time. Way to go.");
    } else {
        return AbstractRoomAction::Drop();
    }
}
