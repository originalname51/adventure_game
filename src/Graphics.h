//
// Created by mpalmer on 10/10/2016.
//



#ifndef FINALADVENTUREPROJECT_GRAPHICS_H
#define FINALADVENTUREPROJECT_GRAPHICS_H

#include <string>
#include <vector>
#include "Menu.h"
#include "Animation.h"
#include "Screen.h"

class Graphics {
private:
    Menu startMenu;
    Menu saveMenu;
    std::vector<Animation *> animations;
    Screen screen;
public:
    void setRoom(std::string roomName);
    void setScore(int newScore);
    int displayMenu(std::string menuName);
    bool animation(std::string animationName);
    bool displayText(std::string text);
    std::string displayQuestion(std::string question);
};


#endif //FINALADVENTUREPROJECT_GRAPHICS_H
