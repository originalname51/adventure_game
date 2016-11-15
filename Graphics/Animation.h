//
// Created by mpalmer on 10/10/2016.
//

#ifndef FINALADVENTUREPROJECT_ANIMATION_H
#define FINALADVENTUREPROJECT_ANIMATION_H


#include <string>
#include <curses.h>
#include "Screen.h"

#define FRAMES_PER_SECOND 24
#define MICROSECONDS_PER_SECOND 1000000

class Animation {
protected:
    std::string name;
    std::string description;
public:
    Animation(){
        name = "";
        description = "";
    }
    std::string getName(){return name;}
    std::string getDescription(){return description;}
    virtual bool displayAnimation(Screen &screen) = 0;
};


#endif //FINALADVENTUREPROJECT_ANIMATION_H
