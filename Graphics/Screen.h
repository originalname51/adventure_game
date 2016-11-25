//
// Created by mpalmer on 10/10/2016.
//

#ifndef FINALADVENTUREPROJECT_SCREEN_H
#define FINALADVENTUREPROJECT_SCREEN_H

#include <string>
#include <curses.h>
#include <unistd.h>
#include <vector>

#define MAX_INPUT_LENGTH 100

class Screen {
private:
    int cursor[2];
    volatile int screenSize[2];          /* 0 = Y, 1 = X */
    std::string currentRoom;
    std::string score;
    std::string currentText;
    std::vector<std::string> textFragments;
    int currentFragment;
    int colorCounter;
    int textMaxLength;
    int currPosition;

    WINDOW *infoScreen;
    WINDOW *textScreen;
    WINDOW *inputScreen;
    WINDOW *animationScreen;
    bool animationMode;

    void initializeScreenSize();
    bool clearWindow(WINDOW *window);
    void updateInfo();
    void refreshInput();
    void updateTextMaxLength();
    void indicateMoreText();

public:
    // Constructors
    Screen();
    Screen(int startScore, std::string startRoom);

    // Accessors
    int getScreenSizeX(){
        refresh();
        screenSize[1] = getmaxx(stdscr);
        return screenSize[1];
    }
    int getScreenSizeY(){
        refresh();
        screenSize[0] = getmaxy(stdscr);
        return screenSize[0];
    }

    // Mutators
    void setRoom(std::string roomName);
    void setScore(int newScore);

    // General Functions
    bool displayText(std::string text);
    std::string getInput();
    void updateScreenSize();

    // Functions for animations
    bool startAnimation();
    bool endAnimation();
    bool refreshScreen();
    bool clearScreen();
    int createColor(short foregroundColor, short backgroundColor);
    bool turnAttrOn(int attribute);
    bool turnAttrOff(int attribute);
    bool printString(std::string text, int y, int x);

    // Destructor
    ~Screen();
};


#endif //FINALADVENTUREPROJECT_SCREEN_H
