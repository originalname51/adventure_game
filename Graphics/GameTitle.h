//
// Created by mpalmer on 10/29/2016.
//

#ifndef ITEM_TEST_GAMETITLE_H
#define ITEM_TEST_GAMETITLE_H


#include <string>
#include <curses.h>
#include "Animation.h"
#include "Screen.h"

#define FRAMES_PER_SECOND 24
#define MICROSECONDS_PER_SECOND 1000000
#define LEFT 0
#define RIGHT 1
#define DOWN 1
#define UP 0

struct word{
    std::string text;
    int screenLocation[2];
};


class GameTitle : public Animation{
private:
    // Game title text
    struct word firstWord;
    struct word secondWord;
    struct word thirdWord;
    struct word fourthWord;
    std::string title;

    // The helper functions
    void moveInText(Screen &screen, int color);
    void drawBorder(Screen &screen, int color);
    void wipeTitle(Screen &screen, int color1, int color2);
    int calculateNewPosition(int currentPos, int animationLength, int start, int finish, bool direction);

public:
    // Constructor
    GameTitle();

    // Public Methods
    bool displayAnimation(Screen &screen);
};


#endif //ITEM_TEST_GAMETITLE_H
