//
// Created by rob on 10/10/16.
//

#include "KeyRoomAction.h"

KeyRoomAction::KeyRoomAction(ItemTable *iList, Command *commands) : itemList(iList), commands(commands){}

ActionResults  *  KeyRoomAction::Throw() {

    std::string information;

    if(commands->getMainItem() != BACKPACK) {
        information = "You can not throw an item that you do not currently "
                "have in your backpack. Pick up item in order to throw it.";
        ActionResults * results = new ActionResults(CURRENT,information);
        return results;
    }

    switch(commands->getMainItem()) {
        case FOX_TOKEN :
                if (getIsGooseHere()) {
                information = "You throw the fox token at the goose. "
                        "You see faint translucent tendrils reach out of the rock,"
                        "trying to attach to the goose token, as if"
                        "attempting to surround and consume it. The tendrils dissapear in a puff"
                        "when the token hits the floor.";
            } else {
                if (commands->getActedOnItem() == NOTHING) {
                    information = "You throw the fox token with all your might. It barely "
                            "makes it from your hand before being"
                            "pulled to the ground. Throwing this token will not do much for you.";
                }
                    else {
                    information = "Throwing the token does nothing";
                }
            }
            break;

        case GOOSE_TOKEN:
             if (isBeanToken()) {
                information = "You throw the Goose Token at the Bean Token."
                        "You see a flash of predatory excitement as the token"
                        "lands next to the Bean Token.";
            } else if(commands->getActedOnItem() == NOTHING){

                    information = "You throw the fox token with all your might. It barely "
                            "makes it from your hand before being"
                            "pulled to the ground. Throwing this token will not do much for you.";

            } else if(commands->getActedOnItem()==FOX_TOKEN && itemInRoom(FOX_TOKEN)) {
                 information = "A shriek fills the room as you throw the Token."
                         "It appears to be from the goose token.";
            }
    break;

    case BEAN_TOKEN :
        if (commands->getActedOnItem() == GOOSE_TOKEN && itemInRoom(GOOSE_TOKEN)) {
            information = "The bean token crosses the path of the goose token and lands with "
                    "an audible, dead, thud. The goose token ";
        }
            if(commands->getActedOnItem() == NOTHING) {
                information = "The bean token falls to the ground listless.";
            }

    }
}

bool KeyRoomAction::itemInRoom(itemType item) const {
    return itemList->getValue(item)->getLocation()
           == itemList->getValue(PLAYER)->getLocation();
}

bool KeyRoomAction::isBeanToken() const {
    return commands->getActedOnItem() == BEAN_TOKEN &&
                 itemList->getValue(BEAN_TOKEN)->getLocation()
                 == itemList->getValue(PLAYER)->getLocation();
}


bool KeyRoomAction::getIsGooseHere() const {
    return commands->getActedOnItem() == GOOSE_TOKEN &&
           itemList->getValue(GOOSE_TOKEN)->getLocation() == itemList->getValue(PLAYER)->getLocation();
}
