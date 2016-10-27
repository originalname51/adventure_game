//
// Created by mpalmer on 10/10/2016.
//

#ifndef FINALADVENTUREPROJECT_SCREEN_H
#define FINALADVENTUREPROJECT_SCREEN_H

#include <string>
#include <curses.h>

#define MAX_INPUT_LENGTH 100

class Screen {
private:
    int cursor[2];
    int screenSize[2];
    std::string currentRoom;
    std::string score;
    std::string currentText;
    void updateScreenSize();
    WINDOW *infoScreen;
    WINDOW *textScreen;
    WINDOW *inputScreen;
    WINDOW *animationScreen;
    bool animationMode;

    bool clearWindow(WINDOW *window);
    void updateInfo();

public:
    // Constructors
    Screen();
    Screen(int startScore, std::string startRoom);

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
    bool testAnimation();

    // Destructor
    ~Screen();
};


#endif //FINALADVENTUREPROJECT_SCREEN_H
