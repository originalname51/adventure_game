//
// Created by mpalmer on 10/10/2016.
//

#ifndef FINALADVENTUREPROJECT_ANIMATION_H
#define FINALADVENTUREPROJECT_ANIMATION_H


#include <string>

class Animation {
protected:
    std::string name;
    std::string description;
public:
    std::string getName(){return name}
    std::string getDescription(){return description}
    virtual bool displayAnimation(Screen screen);
};


#endif //FINALADVENTUREPROJECT_ANIMATION_H
