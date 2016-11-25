//
// Created by rob on 10/1/16.
//

#include "AbstractRoomAction.h"
AbstractRoomAction::~AbstractRoomAction(){};

AbstractRoomAction::AbstractRoomAction(ItemTable *iList, Command *commands) : itemList(iList), commands(commands) {}

AbstractRoomAction::AbstractRoomAction(ItemTable * iList) : itemList(iList) {};


void AbstractRoomAction::setCommands(Command * com) {
    commands = com;

}


ActionResults * AbstractRoomAction::Use() {
    std::string information;

    information = "You contemplate using " + itemList->getValue(commands->getMainItem())->getItemName() + " but do not see the use. "
                                                                                                                  "Perhaps you should do or use something else.";
    return new ActionResults(CURRENT, information);
}

ActionResults * AbstractRoomAction::Throw() {

    std::string information;

    if (itemList->getValue(commands->getMainItem())->getLocation() != BACKPACK) {
        information = "You can not throw an item that you do not currently "
                "have in your backpack. Pick up item in order to throw it.";
        return new ActionResults(CURRENT, information);
    }

    information = "You throw the  " + itemList->getValue(commands->getMainItem())->getItemName() + " to the ground";
    itemList->getValue(commands->getMainItem())->setLocation(itemList->getValue(PLAYER)->getLocation());

    return new ActionResults(CURRENT, information);
}


ActionResults * AbstractRoomAction::Look() {
    itemType typeArray [] = {
            //Basic Types of "Items" needed.
            PLAYER, NORTH, SOUTH, EAST, WEST, NOTHING, INVENTORY,

            //Items not used for anything currently.
            SHIH_TZU, NON_EXIST,

            //Items in "Green Room One"
            FOX_TOKEN, BEAN_TOKEN, G_BOAT, GOOSE_TOKEN, TOKEN_DOOR, G_ROOM_STATE,

            //Three Key Room Items
            GREEN_KEY, WHITE_KEY, BLUE_KEY,

            //GREEN Hospital room
            BLOOD_BUCKET, CLEAN_BUCKET, CHAIR,

            //Basin Room and //Kid-key room
            WATER, BASIN,

            //Kid-key room
            KID,

            //BLUE - Misty Room
            GLYPHS, FISH, CEILING,

            //BLUE - Ice Room
            BALL, PIPE,

            //BLUE TORCH
            TORCH,

            //BLUE - Dark Room
            TABLET, STATUE, BOX,

            //BLUE - Mirror Room
            ROPE, WHITE_PILLAR, BLACK_PILLAR,

            //WHITE - Room 2
            NORTH_WALL, EAST_WALL, WEST_WALL,

            //WHITE - PILLAR room
            DISCUS, POWER_CRYSTAL, LIGHT_PILLAR, LADDER, DOOR_W1,

            //WHITE - Table Room
            PITCHER, BOWL, LIGHT

    };
    std::string information;
    if (commands->getMainItem() == INVENTORY) {
    information = "Items in inventory are: ";
    for (itemType item : typeArray) {
               if (itemList->getValue(item)->getLocation() == BACKPACK) {
            information = itemList->getValue(item)->getItemName() + " ";
        }
    }
    return new ActionResults(CURRENT, information);
}
    if (itemInRoom(commands->getMainItem()) ||
        itemList->getValue(commands->getMainItem())->getLocation()
        != BACKPACK) {
        information = "You can not look at an  item that you do not currently "
                "have in your backpack and is not"
                "in the room.";
        return new ActionResults(CURRENT, information);

    }

    switch (commands->getMainItem()) {
        case FOX_TOKEN : {
            information = "You see a token of a toothy fox, spun around in a circle. "
                    "A backdrop of a chicken coop is in the background.";
            break;
        }
        case GOOSE_TOKEN : {
            information = "A fat goose adorns this token.";
            break;
        }
        case BEAN_TOKEN : {
            information = "A giant black bean adorns this token.";
            break;
        }
        default : {
            information = "You look at the  " + itemList->getValue(commands->getMainItem())->getItemName() + ". "
                    "It looks nice.";
        }
    }
    return new ActionResults(CURRENT, information);

}


ActionResults * AbstractRoomAction::Touch() {

    return new ActionResults(CURRENT, "No touching.");

}

ActionResults * AbstractRoomAction::Rest() {
    return new ActionResults(CURRENT, "You rest for a few hours. You wake up feeling refreshed.");
}


ActionResults * AbstractRoomAction::Close() {
    std::string information;

    information = "There is nothing to close.";
    return new ActionResults(CURRENT, information);
}


ActionResults * AbstractRoomAction::Pick() {
    std::string information;

    if (!itemInRoom(commands->getMainItem()) ||
        itemList->getValue(commands->getMainItem())->getLocation()
        == BACKPACK) {
        information = "You can not pick up an item that is not in the room or in your backpack.";
        return new ActionResults(CURRENT, information);

    }

    switch (commands->getMainItem()) {
        case FOX_TOKEN :
        case GOOSE_TOKEN :
        case BEAN_TOKEN :
            if (!hasAToken() && itemInRoom(commands->getMainItem())) {
                information = "You pick up the the " +
                              itemList->getValue(commands->getMainItem())->getItem().getName();
                itemList->getValue(commands->getMainItem())->setLocation(BACKPACK);
            } else {
                information = "Only one token allowed to be picked up at a time.";
            }
            break;
        default:
            if (itemInRoom(commands->getMainItem())) {
                itemList->getValue(commands->getMainItem())->setLocation(BACKPACK);
                information = "You pick up the " + itemList->getValue(commands->getMainItem())->getItemName();
            } else {
                information = "You cant pick up an item that isnt here.";
            }
            break;
    }

    return new ActionResults(CURRENT, information);
}

ActionResults * AbstractRoomAction::Open() {

        return new ActionResults(CURRENT, "You can't open that here.");
}

bool AbstractRoomAction::itemInRoom(itemType item) const {
    return itemList->getValue(item)->getLocation()
           == itemList->getValue(PLAYER)->getLocation();
}
bool AbstractRoomAction::hasAToken() const {
    return itemList->getValue(GOOSE_TOKEN)->getLocation() == BACKPACK
           || itemList->getValue(BEAN_TOKEN)->getLocation() == BACKPACK
           || itemList->getValue(FOX_TOKEN)->getLocation() == BACKPACK;
}
ActionResults  *    AbstractRoomAction::Drop() {
    std::string information;
    itemType item = commands->getMainItem();

    if(itemList->getValue(item)->getLocation() == BACKPACK) {
        dropItem(item);
        information = "Dropped the item " + itemList->getValue(item)->getItemName();
    } else {
        information = "Can not drop an item that isn't in your back pack.";
    }

    return new ActionResults(CURRENT, information);
}

void AbstractRoomAction::dropItem(const itemType &item) const {
    itemList->getValue(item)->setLocation(itemList->getValue(PLAYER)->getLocation());
}

ActionResults * AbstractRoomAction::Action() {

    ActionResults * action;

    switch(commands->getAction()) {
        case GO:
            return Go();
        case THROW:
            return Throw();

        case LOOK:
            return Look();

        case REST:
            return  Rest();

        case TOUCH:
            return Touch();
        case PICK:
            return Pick();

        case DROP:
            return Drop();

        case USE:
            return  Use();

        case OPEN:
            return Open();

        case CLOSE:
            return Close();

        case NO_ACTION:
     //       action = Nothing();
        case HELP:
            return Help();
            break;
        default:
            assert(false); //blow up program is no relevant action.
            break;
            return action;
    }
    return new ActionResults(CURRENT,"Program is broken in Action() class");
}

ActionResults * AbstractRoomAction::Help() {
    std::string info = "Command options and structure  \n"
            "      _________________________________________________  \n"
            "      GO _____ | ex: GO NORTH  \n"
            "      => takes you to the next room in that direction.  \n"
            "      LOOK (or) EXAMINE _____ | ex: LOOK TABLE  \n"
            "      => examines an item/object/feature more closely  \n"
            "      TOUCH ____ | ex: TOUCH STONE  \n"
            "      => Interacts with an item/object/feature  \n"
            "      PICKUP (or) TAKE ____ | ex: PICKUP STATUE  \n"
            "      => attempts to put an item into your inventory  \n"
            "      DROP _____ | ex: DROP PAMPHLET  \n"
            "      => drops an item from your inventory to the floor  \n"
            "      USE _____ | ex: USE ROPE  \n"
            "      => uses an item in a way that you deem natural.  \n"
            "      OPEN _____ | ex: OPEN DOOR  \n"
            "      => Attempts to open an item/object/feature  \n"
            "      CLOSE _____ | ex: CLOSE DOOR  \n"
            "      => Attempts to close an item/object/feature  \n"
            "      HELP | ex: HELP  \n"
            "      => Pretty sure you know what this one does...";

    return new ActionResults(CURRENT,info);
}


