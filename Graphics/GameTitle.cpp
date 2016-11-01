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
    int colors[5];

    // Start the animation
    screen.startAnimation();

    curs_set(0);

    // Set up the colors of the animation
    colors[0] = screen.createColor(COLOR_BLUE, COLOR_BLACK);      /* The original text color          */
    colors[1] = screen.createColor(COLOR_YELLOW, COLOR_YELLOW);   /* The original title border color  */
    colors[2] = screen.createColor(COLOR_WHITE, COLOR_BLUE);      /* The final title & border color   */
    colors[3] = screen.createColor(COLOR_WHITE, COLOR_BLACK);     /* The final title & border color   */
    colors[4] = screen.createColor(COLOR_BLUE, COLOR_WHITE);     /* The final title & border color   */

    // Clear the screen
    screen.clearScreen();

    // Move the text from the corners to the middle of the screen
    screen.turnAttrOn(COLOR_PAIR(colors[2]));
    screen.turnAttrOn(A_BOLD);
    moveInText(screen, colors[0]);
    screen.turnAttrOff(A_BOLD);
    screen.turnAttrOff(COLOR_PAIR(colors[2]));

    // Draw the border
    screen.turnAttrOn(COLOR_PAIR(colors[2]));
    drawBorder(screen, colors[3]);
    screen.turnAttrOff(COLOR_PAIR(colors[2]));

    // Wipe the text and border
    wipeTitle(screen, colors[2], colors[1]);

    curs_set(1);

    // End the animation
    screen.endAnimation();

    return true;
}




// Private Methods

void GameTitle::moveInText(Screen &screen, int color) {
    int animationLength = 2;
    unsigned int frameCounter = 0;
    int totalAnimationFrames = animationLength * FRAMES_PER_SECOND;
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

    fourthWordStartLocation[0] = fourthWord.screenLocation[0] = screen.getScreenSizeY();
    fourthWordStartLocation[1] = fourthWord.screenLocation[1] = 0;

    // Calculate the end positions of the text
    firstWordEndLocation[0] = secondWordEndLocation[0] = thirdWordEndLocation[0] = fourthWordEndLocation[0] = (screen.getScreenSizeY() / 2);

    firstWordEndLocation[1] = ( screen.getScreenSizeX() / 2 ) - ( static_cast<int>( title.length() ) / 2 );
    secondWordEndLocation[1] = firstWordEndLocation[1] + static_cast<int>( firstWord.text.length() );
    thirdWordEndLocation[1] = secondWordEndLocation[1] + static_cast<int>( secondWord.text.length() );
    fourthWordEndLocation[1] = thirdWordEndLocation[1] + static_cast<int>( thirdWord.text.length() );

    // Turn on the color attribute
    //screen.turnAttrOn(COLOR_PAIR(color));

    // Loop through the words until they are all in their respective end positions
    while(static_cast<int>(frameCounter) <= totalAnimationFrames){
        // Print the words on the screen
        screen.clearScreen();
        screen.printString(firstWord.text, firstWord.screenLocation[0], firstWord.screenLocation[1]);
        screen.printString(secondWord.text, secondWord.screenLocation[0], secondWord.screenLocation[1]);
        screen.printString(thirdWord.text, thirdWord.screenLocation[0], thirdWord.screenLocation[1]);
        screen.printString(fourthWord.text, fourthWord.screenLocation[0], fourthWord.screenLocation[1]);

        screen.refreshScreen();
        usleep(MICROSECONDS_PER_SECOND / FRAMES_PER_SECOND);

        // Move the words
        firstWord.screenLocation[0] = calculateNewPosition(firstWord.screenLocation[0],
                                                          animationLength,
                                                          firstWordStartLocation[0],
                                                          firstWordEndLocation[0],
                                                           DOWN);
        firstWord.screenLocation[1] = calculateNewPosition(firstWord.screenLocation[1],
                                                           animationLength,
                                                           firstWordStartLocation[1],
                                                           firstWordEndLocation[1],
                                                           LEFT);
        secondWord.screenLocation[0] = calculateNewPosition(secondWord.screenLocation[0],
                                                           animationLength,
                                                           secondWordStartLocation[0],
                                                           secondWordEndLocation[0],
                                                            DOWN);
        secondWord.screenLocation[1] = calculateNewPosition(secondWord.screenLocation[1],
                                                           animationLength,
                                                           secondWordStartLocation[1],
                                                           secondWordEndLocation[1],
                                                            RIGHT);
        thirdWord.screenLocation[0] = calculateNewPosition(thirdWord.screenLocation[0],
                                                           animationLength,
                                                           thirdWordStartLocation[0],
                                                           thirdWordEndLocation[0],
                                                            UP);
        thirdWord.screenLocation[1] = calculateNewPosition(thirdWord.screenLocation[1],
                                                           animationLength,
                                                           thirdWordStartLocation[1],
                                                           thirdWordEndLocation[1],
                                                           LEFT);
        fourthWord.screenLocation[0] = calculateNewPosition(fourthWord.screenLocation[0],
                                                           animationLength,
                                                           fourthWordStartLocation[0],
                                                           fourthWordEndLocation[0],
                                                            UP);
        fourthWord.screenLocation[1] = calculateNewPosition(fourthWord.screenLocation[1],
                                                           animationLength,
                                                           fourthWordStartLocation[1],
                                                           fourthWordEndLocation[1],
                                                            RIGHT);
        frameCounter++;
    }

    // Turn off the color attribute
    //screen.turnAttrOff(COLOR_PAIR(color));
}

void GameTitle::drawBorder(Screen &screen, int color) {
    screen.clearScreen();
    std::string character = " ";
    std::string startMessage = "<Press Enter to Start Game>";

    // Calculate the text location
    int textStartLocation[2];
    textStartLocation[0] = screen.getScreenSizeY() / 2;
    textStartLocation[1] = (screen.getScreenSizeX() / 2) - (static_cast<int>(title.length()) / 2);

    // Calculate the border dimensions
    int borderHeight = 2;
    int borderWidth = static_cast<int>(title.length()) + 1;

    int borderStartLocation[2];
    int borderCursor[2];

    borderStartLocation[0] = borderCursor[0] = textStartLocation[0] - 1;
    borderStartLocation[1] = borderCursor[1] = textStartLocation[1] - 1;

    // Draw the border
    screen.printString(title, textStartLocation[0], textStartLocation[1]);
    screen.printString(character, borderStartLocation[0], borderStartLocation[1]);
    screen.refreshScreen();
    usleep(MICROSECONDS_PER_SECOND / FRAMES_PER_SECOND / 2);

    borderCursor[1]++;

    bool lineFinished = false;

    while(!lineFinished){
        // Print the border
        screen.printString(character, borderCursor[0], borderCursor[1]);
        screen.refreshScreen();
        usleep(MICROSECONDS_PER_SECOND / FRAMES_PER_SECOND / 2);

        // Move the cursor
        borderCursor[1]++;

        if(borderCursor[1] == (borderStartLocation[1] + borderWidth)){
            lineFinished = true;
        }
    }

    lineFinished = false;
    while(!lineFinished){
        // Print the border
        screen.printString(title, textStartLocation[0], textStartLocation[1]);
        screen.printString(character, borderCursor[0], borderCursor[1]);
        screen.refreshScreen();
        usleep(MICROSECONDS_PER_SECOND / FRAMES_PER_SECOND / 2);

        // Move the cursor
        borderCursor[0]++;

        if(borderCursor[0] == (borderStartLocation[0] + borderHeight)){
            lineFinished = true;
        }
    }

    lineFinished = false;
    while(!lineFinished){
        // Print the border
        screen.printString(title, textStartLocation[0], textStartLocation[1]);
        screen.printString(character, borderCursor[0], borderCursor[1]);
        screen.refreshScreen();
        usleep(MICROSECONDS_PER_SECOND / FRAMES_PER_SECOND / 2);

        // Move the cursor
        borderCursor[1]--;

        if(borderCursor[1] == borderStartLocation[1]){
            lineFinished = true;
        }
    }

    lineFinished = false;
    while(!lineFinished){
        // Print the border
        screen.printString(title, textStartLocation[0], textStartLocation[1]);
        screen.printString(character, borderCursor[0], borderCursor[1]);
        screen.refreshScreen();
        usleep(MICROSECONDS_PER_SECOND / FRAMES_PER_SECOND / 2);

        // Move the cursor
        borderCursor[0]--;

        if(borderCursor[0] == borderStartLocation[0]){
            lineFinished = true;
        }
    }

    screen.printString(startMessage, textStartLocation[0] + 4, textStartLocation[1]);
    screen.refreshScreen();

    screen.getInput();
}

void GameTitle::wipeTitle(Screen &screen, int color1, int color2) {
    std::string blank = " ";
    std::string letter = "";

    // TODO: Write the rest of this function

}

int GameTitle::calculateNewPosition(int currentPos, int animationLength, int start, volatile int finish, bool direction) {
    double positionMove = (finish - start) / (animationLength * FRAMES_PER_SECOND);

    if(positionMove < 1){
        positionMove = 1;
    }

    if(direction == DOWN){
        currentPos += positionMove;

        if(currentPos >= finish){
            currentPos = finish;
        }

        return currentPos;
    }
    else {
        currentPos -= positionMove;

        if(currentPos < finish){
            currentPos = finish;
        }

        return currentPos;
    }

}




