//
// Created by mpalmer on 10/10/2016.
//

#ifndef FINALADVENTUREPROJECT_SCREEN_H
#define FINALADVENTUREPROJECT_SCREEN_H

#include <string>
#include <curses.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

class Screen {
private:
    int cursor[2];
    int screenSize[2];          /* 0 = Y, 1 = X */
    std::string currentRoom;
    std::string score;
    std::string currentText;
    int colorCounter;

    WINDOW *infoScreen;
    WINDOW *textScreen;
    WINDOW *inputScreen;
    WINDOW *animationScreen;
    bool animationMode;

    void updateScreenSize();

    bool clearWindow(WINDOW *window);
    void updateInfo();

public:
    // Constructors
    Screen();
    Screen(int startScore, std::string startRoom);

    // Accessors
    int getScreenSizeX(){
        updateScreenSize();
        return screenSize[1];
    }
    int getScreenSizeY(){
        updateScreenSize();
        return screenSize[0];
    }

    // Mutators
    void setRoom(std::string roomName);
    void setScore(int newScore);

    // General Functions
    bool displayText(std::string text);
    std::string getInput();

    // Functions for animations
    bool startAnimation();
    bool endAnimation();
    bool refreshScreen();
    bool clearScreen();
    int createColor(short foregroundColor, short backgroundColor);
    bool turnAttrOn(int attribute);
    bool turnAttrOff(int attribute);
    bool printString(std::string text, int y, int x);
    //bool testAnimation();

    // Destructor
    ~Screen();
};


#endif //FINALADVENTUREPROJECT_SCREEN_H
