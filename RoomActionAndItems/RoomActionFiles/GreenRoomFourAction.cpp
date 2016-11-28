//
// Created by rob on 11/19/16.
//

#include "GreenRoomFourAction.h"

GreenRoomFourAction::GreenRoomFourAction(ItemTable *iTable) : AbstractRoomAction(iTable) {}

GreenRoomFourAction::GreenRoomFourAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}


ActionResults * GreenRoomFourAction::Look() {

    if(commands->getMainItem() == KID) {
        std::string information = "The child in front of you whispers repeatedly :"
                "aqua, water, ma'an, eau, Wasser, vody....";
        return new ActionResults(CURRENT, information);
    } else if (commands->getMainItem() == CLEAN_BUCKET) {
        std::string information = "You examine the bucket of ice cool water. You see the child's eyes lock on the bucket";
        return new ActionResults(CURRENT, information);
    } else {
        return AbstractRoomAction::Look();
    }

}


ActionResults *GreenRoomFourAction::Use() {

    if(commands->getActedOnItem() != KID)
        return AbstractRoomAction::Use();
    else {
        if (commands->getMainItem() != BUCKET && itemList->getValue(CLEAN_BUCKET)->getLocation() != ACTIVE) {
            return AbstractRoomAction::Use();
        } else {

            std::string information = "The otherworldy child drinks from the clean water basin."
                    "You can see strength return until a large burst of light illuminates the room."
                    "The room completely changes into vibrant gold colours. You have completed this leg of the journey."
                    "The creature now focuses on you, and with a flicker of his eye you hear the words in your ears....GO!\n"
                    "The creature vanishes and you see all doors lead back to the main entrance.";
            itemList->getValue(KID)->setLocation(HIDDEN);
            itemList->getValue(GREEN_KEY)->setLocation(HIDDEN);
            return new ActionResults(CURRENT, information, FIREWORKS);
        }
    }
}

ActionResults * GreenRoomFourAction::Go() {

    if(itemList->getValue(KID)->getLocation() == HIDDEN) {
        return new ActionResults(THREE_KEY_ROOM, "You find yourself in the keyroom again. Your Green Key is gone"
                "and you can not go through the door again.");
    }
    if (commands->getMainItem() == NORTH) {
        return new ActionResults(CURRENT, "You can't go north, you can only go south.\n");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(G_ROOM2_BUCKET, "You go back to green room.\n");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    return new ActionResults(CURRENT,"You can't go there.\n");

}

