//
// Created by mpalmer on 11/10/2016.
//

#include <cmath>
#include <cstdlib>
#include "../Animation.h"
#include "Firework.h"
#define PI 3.14159265359

Firework::Firework(char ball, char stream, char tail, char explosionParticle) {
    fireworkStage = UNITIALIZED;

    this->ball = ball;
    this->stream = stream;
    this->tail = tail;
    this->explosionParticle = explosionParticle;

    streamFrameCounter = 1;
    explosionFrameCounter = 0;
}

bool Firework::initializeFirework(int startX, int endY, int explosionDiameter, int streamerColor, int explosionColor, Screen &screen) {
    // Check to see if the firework has already been initialized
    if(fireworkStage != UNITIALIZED){
        return false;
    }
    else {
        fireworkStage = STREAMER_STAGE;

        currentPosition[0] = screen.getScreenSizeY();
        currentPosition[1] = endPosition[1] = startX;

        endPosition[0] = screen.getScreenSizeY() - endY;

        this->explosionDiameter = explosionDiameter;

        this->streamerColor = streamerColor;
        this->explosionColor = explosionColor;

        return true;
    }
}

bool Firework::display(Screen &screen) {
    if(fireworkStage == UNITIALIZED){
        return false;
    }
    else if(fireworkStage == STREAMER_STAGE) {
        displayStreamer(screen);
        return true;
    }
    else if(fireworkStage == EXPLOSION_STAGE){
        displayFireworkExplosion(screen);
        return true;
    }
    else {
        return false;
    }
}

void Firework::printImage(Screen &screen, int position[], std::vector<std::string> &image) {
    unsigned int i;

    for(i = 0; i < image.size(); i++){
        screen.printString(image[i], position[0] + i, position[1]);
    }
}

void Firework::displayStreamer(Screen &screen) {
    std::vector<std::string> image;


    // Create the streaming ball image
    image.push_back(ball);
    image.push_back(stream);
    image.push_back(tail);

    screen.turnAttrOn(COLOR_PAIR(streamerColor));

    // Loop through the animation until streamer is in the final position
    if(currentPosition[0] != endPosition[0]){
        printImage(screen, currentPosition, image);

        if(streamFrameCounter == 0){
            currentPosition[0] -= 1;
            streamFrameCounter = 1;
        }
        else {
            streamFrameCounter--;
        }
    }
    else{
        fireworkStage = EXPLOSION_STAGE;
    }

    screen.turnAttrOff(COLOR_PAIR(streamerColor));
}

void Firework::displayFireworkExplosion(Screen &screen) {
    double explosionCycleFrames = 3;      /* The number of frames to display the explosion circle                 */
    double explosionTotalTime = 1.5;         /* The total time, in seconds, to display the explosion circle          */

    std::vector<std::string> image;
    double i;
    int j, k;


    // Calculate the start coordinates for printing the 2d string array
    int startCursorPosition[2];
    startCursorPosition[0] = endPosition[0] - (explosionDiameter / 2);
    startCursorPosition[1] = endPosition[1] - (explosionDiameter / 2);

    // Generate the image boundaries
    bool boundaries[explosionDiameter][explosionDiameter];
    for (j = 0; j < explosionDiameter; j++){
        for(k = 0; k < explosionDiameter; k++){
            boundaries[j][k] = false;
        }
    }

    int x, y;
    const int cx = explosionDiameter / 2;
    const int cy = explosionDiameter / 2;
    for(i = 0; i <= (2 * PI); i+= (PI / 360) ){
        // Calculate a point on the edge of the circle
        x = (int)( cx + (explosionDiameter / 2) * cos(i) );
        y = (int)( cy + (explosionDiameter / 2) * sin(i) );

        // Store that point in the boundary array
        boundaries[y][x] = true;
    }

    // Fill in the boundary circle

    bool flag = false;
    for (j = 0; j < explosionDiameter; j++){
        for(k = 0; k < explosionDiameter; k++){
            if(boundaries[j][k] && !flag && j != 0 && j != (explosionDiameter - 1)){
                // Turn on the filling property
                flag = true;
            }
            else if(boundaries[j][k] && flag){
                // The other edge of the boundary circle has been reached
                flag = false;
            }
            else if(flag){
                boundaries[j][k] = true;
            }
        }
    }


    // Generate the image


    // Print the image
    screen.turnAttrOn(COLOR_PAIR(explosionColor));


    if(explosionFrameCounter < explosionTotalTime){
        for (j = 0; j < explosionDiameter; j++){
            for(k = 0; k < explosionDiameter; k++){
                if(boundaries[j][k]){
                    if(rand() % 2){
                        screen.printString(explosionParticle, startCursorPosition[0] + j, startCursorPosition[1] + k);
                    }
                }
            }
        }
        explosionFrameCounter += (explosionCycleFrames / FRAMES_PER_SECOND);
    }
    else{
        fireworkStage = FINISHED;
    }

    screen.turnAttrOff(COLOR_PAIR(explosionColor));
}
