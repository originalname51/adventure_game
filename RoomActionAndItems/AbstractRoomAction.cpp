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
