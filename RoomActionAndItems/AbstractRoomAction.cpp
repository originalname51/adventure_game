//
// Created by rob on 10/1/16.
//

#include "AbstractRoomAction.h"
AbstractRoomAction::~AbstractRoomAction(){};
ActionResults AbstractRoomAction::Help(){
    std::string help = ""
            "Valid commands include:\n"
            "Go, Look, Help, Rest, Touch, Pick-Up\n"
            "Drop, Use, Open, Close";
    return  ActionResults(CURRENT, help);

}

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
            break;
        default:
            assert(false); //blow up program is no relevant action.
            break;
            return action;
    }
    return new ActionResults(CURRENT,"Program is broken in Action() class");
}