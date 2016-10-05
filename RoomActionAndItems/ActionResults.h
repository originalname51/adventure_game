//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ACTIONRESULTS_H
#define FINALADVENTUREPROJECT_ACTIONRESULTS_H
#include <iostream>
#include "../Room.h"

enum specialEffects{ZAP, BOP, ICE, NONE};
class ActionResults {
private:
    const room returnRoom;
    const std::string returnText;
    const specialEffects special;
public:
    ActionResults(room r, std::string t);
    ActionResults(room r, std::string t, specialEffects s);

    int getRoom();
    int getSpecialEffect();
    const std::string getReturnDescription();

};
#endif //FINALADVENTUREPROJECT_ACTIONRESULTS_H
