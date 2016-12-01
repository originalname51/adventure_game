//
// Created by mpalmer on 10/10/2016.
//

#include "Graphics.h"

Graphics::Graphics(){
    // Create the animations array
    animations.push_back(new GameTitle());
    animations.push_back(new Fireworks());

    // TODO: Create the menus
}

Graphics::Graphics(int startScore, std::string startRoom) : screen(startScore, startRoom)
{
    // Create the animations array
    animations.push_back(new GameTitle());
    animations.push_back(new Fireworks());

    // TODO: Create the menus
}

Graphics::~Graphics() {
    unsigned int i;

    for(i = 0; i < animations.size(); i++){
        free(animations[i]);
    }
}


void Graphics::setRoom(std::string roomName) {
    screen.setRoom(roomName);
}

void Graphics::setScore(int newScore) {
    screen.setScore(newScore);
}

bool Graphics::animation(std::string animationName) {
    if(animationName == "explosion"){
        // TODO: Write the animations call methods
        return true;
    }
    else if(animationName == "GameTitle"){
        return animations[0]->displayAnimation(screen);
    }
    else if(animationName == "Fireworks"){
        return animations[1]->displayAnimation(screen);
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

void Graphics::refreshScreen() {
    screen.updateScreenSize();
}









