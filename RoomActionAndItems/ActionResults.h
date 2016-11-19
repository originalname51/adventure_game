//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ACTIONRESULTS_H
#define FINALADVENTUREPROJECT_ACTIONRESULTS_H
#include <iostream>
#include "../Rooms/Room.h"

enum specialEffects{ZAP, BOP, ICE, FIREWORKS, NONE};
class ActionResults {
private:
    const itemLocation   returnRoom;
    const std::string    returnText;
    const specialEffects special;
public:
    ActionResults(itemLocation r, std::string t);
    ActionResults(itemLocation r, std::string t, specialEffects s);

    itemLocation getRoom();
    specialEffects getSpecialEffect();
    const std::string getReturnDescription();

};
#endif //FINALADVENTUREPROJECT_ACTIONRESULTS_H
