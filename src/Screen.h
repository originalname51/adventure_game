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
    void updateScreenSize();
    WINDOW *infoScreen;
    WINDOW *textScreen;
    WINDOW *inputScreen;

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
    bool refreshScreen();
    bool clearScreen();
    bool drawLine(int startLocation[], int length, int direction);
    bool drawCircle(int centerLocation[], int radius);
    bool drawRectangle(int topLeftLocation[], int width, int height);
    bool drawExplosion(int originLocation[]);

    // Destructor
    ~Screen();
};


#endif //FINALADVENTUREPROJECT_SCREEN_H
