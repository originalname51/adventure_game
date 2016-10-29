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
#define MICROSECOND 1000000

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

public:
    // Constructor
    GameTitle();

    // Public Methods
    bool displayAnimation(Screen &screen);
};


#endif //ITEM_TEST_GAMETITLE_H
