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
ActionResults * AbstractRoomAction::Action() {

    ActionResults * action;

    switch(commands->getAction()) {
        case GO:
            action = Go();
            break;
        case THROW:
            action = Throw();
            break;
        case LOOK:
            action = Look();
            break;
        case REST:
            action = Rest();
            break;
        case TOUCH:
            action = Touch();
            break;
        case PICK:
            action = Pick();
            break;
        case DROP:
            action = Drop();
            break;
        case USE:
            action = Use();
            break;
        case OPEN:
            action = Open();
            break;
        case CLOSE:
            action = Close();
            break;
        case NOTHING:
     //       action = Nothing();
            break;
        default:
            assert(false); //blow up program is no relevant action.
            break;

    }
    return action;
}