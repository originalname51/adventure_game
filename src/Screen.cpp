//
// Created by mpalmer on 10/10/2016.
//

#include "Screen.h"

void Screen::updateScreenSize() {

}

bool Screen::displayText(std::string text) {
    return false;
}

bool Screen::displayQuestion(std::string question) {
    return false;
}

bool Screen::refreshScreen() {
    return false;
}

bool Screen::clearScreen() {
    return false;
}

bool Screen::drawLine(int *startLocation, int length, int direction) {
    return false;
}

bool Screen::drawCircle(int *centerLocation, int radius) {
    return false;
}

bool Screen::drawRectangle(int *topLeftLocation, int width, int height) {
    return false;
}

bool Screen::drawExplosion(int *originLocation) {
    return false;
}
