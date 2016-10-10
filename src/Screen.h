//
// Created by mpalmer on 10/10/2016.
//

#ifndef FINALADVENTUREPROJECT_SCREEN_H
#define FINALADVENTUREPROJECT_SCREEN_H

#include <string>
class Screen {
private:
    int cursor[2];
    int screenSize[2];
    void updateScreenSize();
    std::string currentRoom;
    int score;
public:
    // Mutators
    setRoom(std::string roomName){currentRoom = roomName}
    setScore(int newScore){score = newScore}

    // General Functions
    bool displayText(std::string text);
    bool displayQuestion(std::string question);
    bool refreshScreen();
    bool clearScreen();

    // Functions for animations
    bool drawLine(int startLocation[], int length, int direction);
    bool drawCircle(int centerLocation[], int radius);
    bool drawRectangle(int topLeftLocation[], int width, int height);
    bool drawExplosion(int originLocation[]);
};


#endif //FINALADVENTUREPROJECT_SCREEN_H
