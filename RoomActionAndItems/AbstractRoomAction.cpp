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
            "      HELP | ex: [Blank] or HELP  \n"
            "      => Pretty sure you know what this one does...";

    return new ActionResults(CURRENT,info);
}