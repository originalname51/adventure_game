//
// Created by mpalmer on 10/10/2016.
//

#include "Graphics.h"

void Graphics::setRoom(std::string roomName) {
    screen.setRoom(roomName);
}

void Graphics::setScore(int newScore) {
    screen.setScore(newScore);
}

/*int Graphics::displayMenu(std::string menuName) {
    std::string menuOptions = "";
    if(menuName == "start") {
        menuOptions = startMenu.getMenuOptions();
        screen.displayText(menuOptions);
        return std::stoi(screen.getInput());
    }
    else if(menuName == "save"){
        menuOptions = saveMenu.getMenuOptions();
        screen.displayText(menuOptions);
        return std::stoi(screen.getInput());
    }
    else{
        if(DEBUG){
            std::cout << "No valid menu selected." << std::endl;
        }
        return -1;
    }
}*/

bool Graphics::animation(std::string animationName) {
    if(animationName == "explosion"){
        // TODO: Write the animations call methods
        return true;
    }
    else if(animationName == "GameTitle"){
        animations[0]->displayAnimation(screen);
        return true;
    }
    else {
        return false;
    }
}

bool Graphics::displayText(std::string text) {
    return screen.displayText(text);
}

std::string Graphics::getInput() {
    return screen.getInput();
}

Graphics::Graphics(){
    // TODO: Create the animations array
    animations.push_back(new GameTitle());

    // TODO: Create the menus
}

Graphics::Graphics(int startScore, std::string startRoom) : screen(startScore, startRoom)
{
    // TODO: Create the animations array
    animations.push_back(new GameTitle());

    // TODO: Create the menus
}




