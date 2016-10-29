//
// Created by mpalmer on 10/29/2016.
//

#include "GameTitle.h"

// Constructor
GameTitle::GameTitle() {
    // Set the default values of the base class members
    name = "GameTitle";
    description = "A slide-in text animation of the game title. \nIntended for the beginning of the game.";

    // Initialize the private members
    firstWord.text = "Private ";
    secondWord.text = "Keys, ";
    thirdWord.text = "Members ";
    fourthWord.text = "Only";

    title = "Private Keys, Members Only";
}


// Public Methods
bool GameTitle::displayAnimation(Screen &screen) {
    int colors[4];

    // Start the animation
    screen.startAnimation();

    // Set up the colors of the animation
    colors[0] = screen.createColor(COLOR_BLUE, COLOR_BLACK);      /* The original text color          */
    colors[1] = screen.createColor(COLOR_YELLOW, COLOR_YELLOW);   /* The original title border color  */
    colors[2] = screen.createColor(COLOR_WHITE, COLOR_BLUE);      /* The final title & border color   */
    colors[3] = screen.createColor(COLOR_WHITE, COLOR_WHITE);     /* The final title & border color   */

    // Clear the screen
    screen.clearScreen();

    // Move the text from the corners to the middle of the screen
    moveInText(screen, colors[0]);

    // Draw the border
    drawBorder(screen, colors[1]);

    // Wipe the text and border
    wipeTitle(screen, colors[2], colors[3]);

    // End the animation
    screen.endAnimation();

}

void GameTitle::moveInText(Screen &screen, int color) {
    int animationLength = 3;
    int firstWordStartLocation[2];
    int firstWordEndLocation[2];
    int secondWordStartLocation[2];
    int secondWordEndLocation[2];
    int thirdWordStartLocation[2];
    int thirdWordEndLocation[2];
    int fourthWordStartLocation[2];
    int fourthWordEndLocation[2];

    // Set the initial locations of the text
    firstWordStartLocation[0] = firstWord.screenLocation[0] = 0;
    firstWordStartLocation[1] = firstWord.screenLocation[1] = screen.getScreenSizeX() - static_cast<int>(firstWord.text.length());

    secondWordStartLocation[0] = secondWord.screenLocation[0] = 0;
    secondWordStartLocation[1] = secondWord.screenLocation[1] = 0;

    thirdWordStartLocation[0] = thirdWord.screenLocation[0] = screen.getScreenSizeY();
    thirdWordStartLocation[1] = thirdWord.screenLocation[1] = screen.getScreenSizeX() - static_cast<int>(thirdWord.text.length());

    fourthWord.screenLocation[0] = screen.getScreenSizeY();
    fourthWord.screenLocation[1] = 0;

    // Turn on the color attribute
    screen.turnAttrOn(COLOR_PAIR(color));

    // Loop through the words until they are all in place
    while(firstWord.screenLocation[0] != screen.getScreenSizeY() / 2){
        // Print the words on the screen
        screen.clearScreen();
        screen.printString(firstWord.text, firstWord.screenLocation[0], firstWord.screenLocation[1]);
        screen.printString(secondWord.text, secondWord.screenLocation[0], secondWord.screenLocation[1]);
        screen.printString(thirdWord.text, thirdWord.screenLocation[0], thirdWord.screenLocation[1]);
        screen.printString(fourthWord.text, fourthWord.screenLocation[0], fourthWord.screenLocation[1]);

        screen.refreshScreen();
        usleep(FRAMES_PER_SECOND / MICROSECOND);

        // Move the words


    }

    // Turn off the color attribute
    screen.turnAttrOff(COLOR_PAIR(color));
}

void GameTitle::drawBorder(Screen &screen, int color) {

}

void GameTitle::wipeTitle(Screen &screen, int color1, int color2) {

}


// Private Methods

