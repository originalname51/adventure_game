//
// Created by rob on 10/1/16.
//

#include "ActionResults.h"

ActionResults::ActionResults(itemLocation r, std::string t)
        : returnRoom(r), returnText(t),special(NONE){};

ActionResults::ActionResults(itemLocation r, std::string t, specialEffects s)
        : returnRoom(r), returnText(t), special(s){};

itemLocation ActionResults::getRoom(){
    return returnRoom;
}

specialEffects ActionResults::getSpecialEffect(){
    return special;
}
const std::string ActionResults::getReturnDescription(){
    return returnText;
}