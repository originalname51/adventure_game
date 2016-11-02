//
// Created by mpalmer on 10/10/2016.
//

#include <unistd.h>
#include "Screen.h"


// Constructors

Screen::Screen() {
    // Set the default values for all private methods
    cursor[0] = 0;  // Y
    cursor[1] = 0;  // X
    score = "0";
    currentRoom = " ";
    colorCounter = 0;

    // Initialize the ncurses screen
    initscr();
    // raw();
    refresh();
    start_color();

    // Get the current size of the screen
    updateScreenSize();

    // Create the windows for the program
    infoScreen = newwin(3, screenSize[1], 0, 0);
    textScreen = newwin((screenSize[0] - 6), screenSize[1], 3, 0);
    inputScreen = newwin(3, screenSize[1], (screenSize[0] - 6), 0);

    // Turn off animation mode
    animationMode = false;
}

Screen::Screen(int startScore, std::string startRoom) {
    // Set the default values for all private methods
    cursor[0] = 0;  // Y
    cursor[1] = 0;  // X
    score = std::to_string(startScore);
    currentRoom = startRoom;
    colorCounter = 0;

    // Initialize the ncurses screen
    initscr();
    // raw();
    refresh();
    start_color();

    // Get the current size of the screen
    updateScreenSize();

    // Create the windows for the program
    infoScreen = newwin(3, screenSize[1], 0, 0);
    textScreen = newwin((screenSize[0] - 6), screenSize[1], 3, 0);
    inputScreen = newwin(3, screenSize[1], (screenSize[0] - 6), 0);

    // Turn off animation mode
    animationMode = false;
}


// Desctructor

Screen::~Screen() {
    // Delete the windows
    delwin(infoScreen);
    delwin(textScreen);
    delwin(inputScreen);
    delwin(animationScreen);

    // Delete the default window
    endwin();
}



// Public Methods

void Screen::setScore(int newScore){
    score = std::to_string(newScore);

    // Display the updated score
    updateInfo();
}

void Screen::setRoom(std::string roomName) {
    currentRoom = roomName;

    // Display the updated room
    updateInfo();
}

void Screen::updateScreenSize() {
    // Get the current size of the screen
    screenSize[0] = getmaxy(stdscr);
    screenSize[1] = getmaxx(stdscr);
}

bool Screen::displayText(std::string text) {
    if(!animationMode){
        // Update the info area
        updateInfo();

        // Remove any unwanted text
        clearWindow(textScreen);

        // Save the message
        currentText = text;

        // Print the message
        wprintw(textScreen, currentText.c_str());

        // Display the message
        wrefresh(textScreen);

        return true;
    }
    else{
        // Print the message
        wprintw(animationScreen, text.c_str());

        // Display the message
        wrefresh(animationScreen);

        return true;
    }
}

std::string Screen::getInput() {
    std::string formattedInput;
    char inputText[MAX_INPUT_LENGTH];
    inputText[0] = '\0';

    // Clear the input area
    clearWindow(inputScreen);
    wrefresh(inputScreen);

    // Move the cursor to the correct location
    mvwprintw(inputScreen, 1, 1, "> ");

    // Get a string of console input
    wgetstr(inputScreen, inputText);

    formattedInput = std::string(inputText);

    return formattedInput;
}

bool Screen::refreshScreen() {
    updateScreenSize();
    wrefresh(animationScreen);

    return true;
}

bool Screen::clearScreen() {
    updateScreenSize();
    wclear(animationScreen);
    return true;
}


// Functions for the Animation class

bool Screen::startAnimation() {
    // Get the current size of the screen
    updateScreenSize();

    // Create the windows for the program
    animationScreen = newwin(getScreenSizeY(), getScreenSizeX(), 0, 0);

    wrefresh(animationScreen);

    animationMode = true;

    return true;
}

bool Screen::endAnimation() {
    // Clear out the window's data structure
    wclear(animationScreen);
    wrefresh(animationScreen);

    // Delete the window
    delwin(animationScreen);

    // Turn off animation mode
    animationMode = false;

    // Replace the screen contents
    updateInfo();

    displayText(currentText);

    return true;
}

int Screen::createColor(short foregroundColor, short backgroundColor) {
    colorCounter++;
    init_pair(static_cast<short>(colorCounter), foregroundColor, backgroundColor);

    return colorCounter;
}

bool Screen::turnAttrOn(int attribute) {
    wattron(animationScreen, attribute);

    return true;
}

bool Screen::turnAttrOff(int attribute) {
    wattroff(animationScreen, attribute);

    return true;
}

bool Screen::printString(std::string text, int y, int x) {
    // Check for valid start coordinates
    if(y > getScreenSizeY() || x > getScreenSizeX()){
        return false;
    }
    else {
        // Ensure that printed text is not off the screen
        mvwprintw(animationScreen, y, x, text.c_str());

        return true;
    }
}

//bool Screen::testAnimation() {
//    std::string text = "Boom!";
//    int colorPair1 = -1;
//    int colorPair2 = -1;
//    // Animation mode assumed to be on
//
//    // Clear the animation screen
//    clearScreen();
//    refreshScreen();
//
//    // Set up some colors
//    colorPair1 = createColor(COLOR_RED, COLOR_WHITE);
//    colorPair2 = createColor(COLOR_WHITE, COLOR_RED);
//
//    // Print some red text
//    for(int i = 0; i < 200; i++){
//        wattron(animationScreen, COLOR_PAIR(colorPair1));
//        mvwprintw(animationScreen, (screenSize[0] / 2), (screenSize[1] / 2), text.c_str());
//        refreshScreen();
//        wattroff(animationScreen, COLOR_PAIR(colorPair1));
//        usleep(1000);
//        wattron(animationScreen, COLOR_PAIR(colorPair1));
//        mvwprintw(animationScreen, (screenSize[0] / 2), (screenSize[1] / 2), text.c_str());
//        refreshScreen();
//        wattroff(animationScreen, COLOR_PAIR(colorPair1));
//        usleep(1000);
//    }
//
//    // Clear the screen
//    clearScreen();
//
//    return true;
//}



// Private Methods

void Screen::updateInfo() {
    std::string scoreText = "Progress: ";
    std::string roomText = "Room: ";

    // Clear the info window
    clearWindow(infoScreen);

    // Refresh the screen size
    updateScreenSize();

    // Print out the score
    mvwprintw(infoScreen, 1, 1, scoreText.c_str());
    wprintw(infoScreen, score.c_str());

    // Print out the current room
    mvwprintw(infoScreen, 1, ( screenSize[1] / 2), roomText.c_str() );
    wprintw(infoScreen, currentRoom.c_str());

    wrefresh(infoScreen);
    wrefresh(inputScreen);
}

bool Screen::clearWindow(WINDOW *window) {
    wclear(window);

    return true;
}