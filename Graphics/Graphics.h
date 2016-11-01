//
// Created by mpalmer on 10/10/2016.
//



#ifndef FINALADVENTUREPROJECT_GRAPHICS_H
#define FINALADVENTUREPROJECT_GRAPHICS_H

#include <string>
#include <vector>
#include <iostream>
//#include "Menu.h"
#include "Animation.h"
#include "Screen.h"
#include "GameTitle.h"

class Graphics {
private:
    // Menu startMenu;
    // Menu saveMenu;
    std::vector<Animation *> animations;
    Screen screen;
public:
    // Default Constructor
    Graphics();

    // Preferred Constructor
    Graphics(int startScore, std::string startRoom);

    // Public Methods
    void setRoom(std::string roomName);
    void setScore(int newScore);
    bool animation(std::string animationName);
    bool displayText(std::string text);
    std::string getInput();
};


#endif //FINALADVENTUREPROJECT_GRAPHICS_H
