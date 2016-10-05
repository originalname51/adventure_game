//
// Created by rob on 10/1/16.
//

#include "ActionResults.h"

ActionResults::ActionResults(room r, std::string t)
        : returnRoom(r), returnText(t),special(NONE){};

ActionResults::ActionResults(room r, std::string t, specialEffects s)
        : returnRoom(r), returnText(t), special(s){};

int ActionResults::getRoom(){
    return returnRoom;
}

int ActionResults::getSpecialEffect(){
    return special;
}
const std::string ActionResults::getReturnDescription(){
    return returnText;
}