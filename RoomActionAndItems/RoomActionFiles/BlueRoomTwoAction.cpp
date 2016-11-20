//
// Created by rob on 11/19/16.
//

#include "BlueRoomTwoAction.h"

BlueRoomTwoAction::BlueRoomTwoAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

BlueRoomTwoAction::BlueRoomTwoAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *BlueRoomTwoAction::Look() {

    std::string information;

    switch(commands->getMainItem())
    {
        case GLYPHS:
            if (itemList->getValue(FISH)->getLocation() == BACKPACK) {
                information = "The glyphs seem to shimmer for a moment, but then you are looking at"
                        " perfectly clear and legible English. The wall admonishes you to \"GET A TORCH. WE'RE NOT KIDDING. LOOK AT THE TORCHES IN THE"
                        " PREVIOUS ROOM AND YOU SHOULD BE ABLE TO FIND ONE THAT IS NOT SECURED. THAT IS ALL.\" Funny that they (whoever) bothered to write \"That is all…\"";
            } else {
                information = "The glyphs seem ancient to you, but honestly, "
                        "you wouldn't be able to tell if they were written last year. Oh look, that shape looks like a fish!";
            }
            break;

        case CEILING:
                if (itemList->getValue(FISH)->getLocation() == HIDDEN) {
                    information = "You look up at what appears to be a window covered by water."
                            " The longer you stare at it, the more reflective it becomes. "
                            "Suddenly you can make out your own reflection, and beside it in the image is a small, fish.";
                    itemList->getValue(FISH)->setLocation(B_ROOM2);
                } else {
                    information = "\"You look up at what appears to be a window covered by water.\"\n"
                            "                            \" The longer you stare at it, the more reflective it becomes. \"";
                }
            break;
        default:
            return AbstractRoomAction::Look();

    }
    return new ActionResults(CURRENT, information);
}

ActionResults * BlueRoomTwoAction::Go() {

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(CURRENT, "You can't go north, you can only go south.\n");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(B_ROOM1, "You go back to the torch room.\n");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south..\n");
    }
    return new ActionResults(CURRENT,"You can't go there.\n");

}
