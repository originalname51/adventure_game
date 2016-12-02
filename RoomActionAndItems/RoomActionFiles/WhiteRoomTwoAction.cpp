//
// Created by rob on 11/20/16.
//

#include "WhiteRoomTwoAction.h"

WhiteRoomTwoAction::WhiteRoomTwoAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {

}

WhiteRoomTwoAction::WhiteRoomTwoAction(ItemTable *iTable) : AbstractRoomAction(iTable) {

}

ActionResults *WhiteRoomTwoAction::Go() {

    std::string information = "Climbing ladders is great exercise. You return to the previous room.";

    switch(commands->getMainItem()) {
        case LADDER :
            return new ActionResults(W_ROOM1, information);
        case SOUTH  :
            if (westWallRead && northWallRead && eastWallRead) {
                return new ActionResults(W_ROOM3, "You travel through to the next room");
            } else {
                return new ActionResults(CURRENT, "The large stone door on the south wall is locked. You might need to look around for something to unlock it.");
            }
        default :
            if (roomLit){
                return new ActionResults(CURRENT, "Is running into walls your thing?");
            }
            else {
                return new ActionResults(CURRENT, "Unless you brought your night-vision goggles, it's probably not a good idea to grope around in the dark.");
            }

    }
}

ActionResults *WhiteRoomTwoAction::Use() {
    if((commands->getMainItem() == POWER_CRYSTAL
        && commands->getActedOnItem() == LIGHT_PILLAR
        && itemList->getValue(POWER_CRYSTAL)->getLocation() == BACKPACK)
       || (commands->getMainItem() == TORCH &&
            itemList->getValue(TORCH)->getLocation() == BACKPACK)) {
        roomLit = true;
        return new ActionResults(CURRENT, "The power crystal refracts the pillar of light and splashes colorful beams of light on the "
                "east, west, and north walls. You feel compelled to read each wall, almost as if it is a requirement to "
                "progress down this path.");
    } else if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() == BACKPACK && commands->getActedOnItem() == LIGHT_PILLAR){
        return new ActionResults(CURRENT, "The reflected light reveals very reflective, although empty walls to the east, north, and west. Maybe white light isn't the best for this room's decor.");
    }
    else if (commands->getMainItem() == LADDER){
        return new ActionResults(W_ROOM1, "You climb up the ladder");
    }
    else {
        return AbstractRoomAction::Use();
    }
}

ActionResults *WhiteRoomTwoAction::Look() {
    std::string information;

    if(roomLit && !(westWallRead && eastWallRead && northWallRead)){
        switch(commands->getMainItem()) {

            case EAST_WALL:
                if(northWallRead && westWallRead){
                    information = "Three, let's go! The south wall opens up revealing the room's exit.";
                }
                else{
                    information = "One for the money...";
                }
                eastWallRead = true;
                break;
            case WEST_WALL:
                westWallRead = true;
                if(northWallRead && eastWallRead){
                    information = "Three, let's go! The south wall opens up revealing the room's exit.";
                }
                else{
                    information = "Three to get ready...";
                }

                break;
            case NORTH_WALL:
                northWallRead = true;
                if(westWallRead && eastWallRead){
                    information = "Three, let's go! The south wall opens up revealing the room's exit.";
                }
                else{
                    information = "Two for the show...";
                }

                break;
            default:
                return AbstractRoomAction::Look();
        }

        return new ActionResults(CURRENT, information);
    }
    else if(roomLit && (westWallRead && eastWallRead && northWallRead)){
        switch(commands->getMainItem()) {

            case EAST_WALL:

            case WEST_WALL:

            case NORTH_WALL:

                information = "Three, let's go! The south wall opens up revealing the room's exit.";
                break;
            default:
                return AbstractRoomAction::Look();
        }

        return new ActionResults(CURRENT, information);
    }
    else {
        return new ActionResults(CURRENT, "It's dark. Really dark. As in you can't see. As in you need something to see.");
    }
}

ActionResults *WhiteRoomTwoAction::Pick() {
    if(commands->getMainItem() == POWER_CRYSTAL && itemList->getValue(POWER_CRYSTAL)->getLocation() == W_ROOM2){
        itemList->getValue(POWER_CRYSTAL)->setLocation(BACKPACK);
        return new ActionResults(CURRENT, "Nice, you're well on your way to completing your shiny object collection.");
    }
    else if(commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() == W_ROOM2){
        itemList->getValue(DISCUS)->setLocation(BACKPACK);
        return new ActionResults(CURRENT, "I knew you couldn't let go of that Cyndi Lauper song.");
    }
    else {
        return AbstractRoomAction::Pick();
    }
}

ActionResults *WhiteRoomTwoAction::Drop() {
    if (commands->getMainItem() == POWER_CRYSTAL && itemList->getValue(POWER_CRYSTAL)->getLocation() == BACKPACK){
        itemList->getValue(POWER_CRYSTAL)->setLocation(W_ROOM2);
        return new ActionResults(CURRENT, "Uh... okay, you nicely place the crystal on the floor.");
    }
    else if (commands->getMainItem() == DISCUS && itemList->getValue(DISCUS)->getLocation() == BACKPACK) {
        itemList->getValue(DISCUS)->setLocation(W_ROOM2);
        return new ActionResults(CURRENT, "Don't scratch it, you might lose your favorite song. It clangs to the floor in front of you.");
    }
    else {
        return AbstractRoomAction::Drop();
    }
}

ActionResults *WhiteRoomTwoAction::Rest() {
    if(roomLit){
        return new ActionResults(CURRENT, "After sitting down, you begin to realize that this room reminds you of your last 80's disco party. ");
    }
    else if(itemList->getValue(POWER_CRYSTAL)->getLocation() == W_ROOM2) {
        return new ActionResults(CURRENT, "As you sit down, something pokes you in the rumpus. It feels like a crystal.");
    }
    else {
        return new ActionResults(CURRENT, "You and Bruce Wayne have something in common. You both like hanging out in the dark.");
    }
}


