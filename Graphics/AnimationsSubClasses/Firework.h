//
// Created by mpalmer on 11/10/2016.
//

#ifndef ITEM_TEST_FIREWORK_H
#define ITEM_TEST_FIREWORK_H

#include <string>
#include <vector>
#include "../Screen.h"

#define UNITIALIZED 0
#define STREAMER_STAGE 1
#define EXPLOSION_STAGE 2
#define FINISHED 4


class Firework {
private:
    std::string ball;
    std::string stream;
    std::string tail;
    std::string explosionParticle;
    int currentPosition[2];
    int endPosition[2];
    int explosionDiameter;
    int streamerColor;
    int explosionColor;
    int fireworkStage;
    int streamFrameCounter;
    double explosionFrameCounter;

public:
    Firework(char ball, char stream, char tail, char ExplosionParticle);
    bool initializeFirework(int startX, int endY, int explosionDiameter, int streamerColor, int explosionColor, Screen &screen);
    bool display(Screen &screen);

    void printImage(Screen &screen, int *position, std::vector<std::string> &image);

    void displayStreamer(Screen &screen);

    void displayFireworkExplosion(Screen &screen);
};


#endif //ITEM_TEST_FIREWORK_H
