//
// Created by mpalmer on 10/10/2016.
//

#include "Screen.h"


// Constructors

Screen::Screen() {
    // Set the default values for all private methods
    cursor[0] = 0;  // Y
    cursor[1] = 0;  // X
    score = "0";
    currentRoom = " ";

    // Initialize the ncurses screen
    initscr();
    // raw();
    refresh();

    // Get the current size of the screen
    updateScreenSize();

    // Create the windows for the program
    infoScreen = newwin(3, screenSize[1], 0, 0);
    textScreen = newwin((screenSize[0] - 6), screenSize[1], 3, 0);
    inputScreen = newwin(3, screenSize[1], (screenSize[0] - 6), 0);
}

Screen::Screen(int startScore, std::string startRoom) {
    // Set the default values for all private methods
    cursor[0] = 0;  // Y
    cursor[1] = 0;  // X
    score = startScore;
    currentRoom = startRoom;

    // Initialize the ncurses screen
    initscr();
    // raw();
    refresh();

    // Get the current size of the screen
    updateScreenSize();

    // Create the windows for the program
    infoScreen = newwin(3, screenSize[1], 0, 0);
    textScreen = newwin((screenSize[0] - 6), screenSize[1], 3, 0);
    inputScreen = newwin(3, screenSize[1], (screenSize[0] - 6), 0);
}


// Desctructor

Screen::~Screen() {
    // Delete the windows
    delwin(infoScreen);
    delwin(textScreen);
    delwin(inputScreen);

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
    // Remove any unwanted text
    clearWindow(textScreen);

    // Print the message
    wprintw(textScreen, text.c_str());

    // Display the message
    wrefresh(textScreen);
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
    refresh();

    return true;
}

bool Screen::clearScreen() {
    return clear() != 0;
}


// Functions for the Animation class

bool Screen::drawLine(int *startLocation, int length, int direction) {
    // TODO: Not implemented

    return false;
}

bool Screen::drawCircle(int *centerLocation, int radius) {
    // TODO: Not implemented

    return false;
}

bool Screen::drawRectangle(int *topLeftLocation, int width, int height) {
    // TODO: Not implemented

    return false;
}

bool Screen::drawExplosion(int *originLocation) {
    // TODO: Not implemented

    return false;
}



// Private Methods

void Screen::updateInfo() {
    std::string scoreText = "Score: ";
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






