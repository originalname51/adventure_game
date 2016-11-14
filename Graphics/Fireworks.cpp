//
// Created by mpalmer on 11/8/2016.
//

#include "Fireworks.h"



bool Fireworks::displayAnimation(Screen &screen){

    screen.startAnimation();

    // Create the colors
    int streamerColor = screen.createColor(COLOR_YELLOW, COLOR_BLACK);
    int explosionColors[3];
    explosionColors[0] = screen.createColor(COLOR_CYAN, COLOR_BLACK);
    explosionColors[1] = screen.createColor(COLOR_GREEN, COLOR_BLACK);
    explosionColors[2] = screen.createColor(COLOR_MAGENTA, COLOR_BLACK);
    Firework firework1('o', '|', ':', '.');
    Firework firework2('o', '|', ':', 'x');
    Firework firework3('o', '|', ':', '.');

    firework1.initializeFirework(screen.getScreenSizeX() / 4,
                                 screen.getScreenSizeY() / 2,
                                 12,
                                 streamerColor,
                                 explosionColors[0],
                                 screen);

    firework2.initializeFirework(screen.getScreenSizeX() / 4 * 3,
                                 screen.getScreenSizeY() / 2,
                                 14,
                                 streamerColor,
                                 explosionColors[1],
                                 screen);
    firework3.initializeFirework(screen.getScreenSizeX() / 2,
                                 screen.getScreenSizeY() / 2,
                                 16,
                                 streamerColor,
                                 explosionColors[2],
                                 screen);

    // Set the delay between the two fireworks
    int delay1 = 1 * FRAMES_PER_SECOND / 2;
    int delay2 = delay1 * 2;
    bool activeFireworkFlag = true;

    // Loop until both fireworks are done displaying
    while (activeFireworkFlag){
        screen.clearScreen();
        activeFireworkFlag = firework1.display(screen);

        // Delay the second firework
        if (delay1 > 0){
            delay1 --;
        }
        else {
            activeFireworkFlag = firework2.display(screen);
        }

        if(delay2 > 0){
            delay2--;
        }
        else {
            activeFireworkFlag = firework3.display(screen);
        }

        screen.refreshScreen();
        usleep(MICROSECONDS_PER_SECOND / FRAMES_PER_SECOND);
    }


    screen.endAnimation();
    return true;
}


