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
    currentFragment = 0;

    // Initialize the ncurses screen
    initscr();
    // raw();
    refresh();
    start_color();

    // Get the current size of the screen
    initializeScreenSize();

    // Create the windows for the program
    infoScreen = newwin(3, getScreenSizeX(), 0, 0);
    textScreen = newwin((getScreenSizeY() - 6), getScreenSizeX() - 2, 3, 1);
    inputScreen = newwin(3, getScreenSizeX(), (getScreenSizeY() - 3), 0);

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
    currentFragment = 0;

    // Initialize the ncurses screen
    initscr();
    // raw();
    refresh();
    start_color();

    // Get the current size of the screen
    initializeScreenSize();

    // Create the windows for the program
    infoScreen = newwin(3, getScreenSizeX(), 0, 0);
    textScreen = newwin((getScreenSizeY() - 6), getScreenSizeX() - 2, 3, 1);
    inputScreen = newwin(3, getScreenSizeX(), (getScreenSizeY() - 3), 0);

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

bool Screen::displayText(std::string text) {
    int i;
    std::vector<std::string> textFragments;

    if(!animationMode){
        // Update the info area
        updateInfo();

        // Remove any unwanted text
        clearWindow(textScreen);

        // Print the message
        if (text.length() > (unsigned int)textMaxLength){
            currPosition = 0;
            while((unsigned int)currPosition < text.length()){
                textFragments.push_back(text.substr((unsigned long)currPosition, (unsigned long)(currPosition + textMaxLength)));
                currPosition += textMaxLength;
            }

            for(i = currentFragment; (unsigned int)i < textFragments.size(); i++, currentFragment++){
                wclear(textScreen);
                wprintw(textScreen, textFragments[i].c_str());
                wrefresh(textScreen);

                // Reset the counter
                if((unsigned int)i == textFragments.size() - 1){
                    currentFragment = 0;
                    refreshInput();
                    continue;
                }
                else {
                    indicateMoreText();
                }
            }
        }
        else {
            currentText = text;
            wprintw(textScreen, currentText.c_str());

            // Display the message
            wrefresh(textScreen);
        }



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
// Private Methods

void Screen::initializeScreenSize() {
    getScreenSizeY();
    getScreenSizeX();
}

void Screen::updateScreenSize() {
    // Check for a changed screen size
    int screenSizeY = getmaxy(stdscr);
    int screenSizeX = getmaxx(stdscr);
    updateTextMaxLength();

    if(screenSize[0] != screenSizeY || screenSize[1] != screenSizeX){
        getScreenSizeY();
        getScreenSizeX();

        clearScreen();

        // The screen has been resized by the user,
        // Delete the windows and reprint the information
        if(animationMode){
            delwin(animationScreen);

            animationScreen = newwin(getScreenSizeY(), getScreenSizeX(), 0, 0);

            wrefresh(animationScreen);
        }
        else{
            if(infoScreen){
                delwin(infoScreen);
                infoScreen = newwin(3, getScreenSizeX(), 0, 0);
                updateInfo();
                wrefresh(infoScreen);
            }

            if(inputScreen){
                delwin(textScreen);
                textScreen = newwin((getScreenSizeY() - 6), getScreenSizeX() - 2, 3, 1);
                displayText(currentText);
                wrefresh(textScreen);
            }

            if(inputScreen){
                delwin(inputScreen);
                inputScreen = newwin(3, getScreenSizeX(), (getScreenSizeY() - 3), 0);
                refreshInput();
            }
        }
    }
}


void Screen::updateInfo() {
    std::string scoreText = "Puzzles solved: ";
    std::string roomText = "Room: ";

    // Clear the info window
    clearWindow(infoScreen);

    // Print out the score
    mvwprintw(infoScreen, 1, 1, scoreText.c_str());
    wprintw(infoScreen, score.c_str());
    wprintw(infoScreen, "%%");

    // Print out the current room
    mvwprintw(infoScreen, 1, ( getScreenSizeX() / 2 ), roomText.c_str() );
    wprintw(infoScreen, currentRoom.c_str());

    wrefresh(infoScreen);
    wrefresh(inputScreen);
}

bool Screen::clearWindow(WINDOW *window) {
    wclear(window);

    return true;
}

void Screen::refreshInput() {
    // Clear the input area
    clearWindow(inputScreen);
    wrefresh(inputScreen);

    // Move the cursor to the correct location
    mvwprintw(inputScreen, 1, 1, "> ");
}

void Screen::updateTextMaxLength() {
    textMaxLength = getmaxx(textScreen) * (getmaxy(textScreen) - 1);
}

void Screen::indicateMoreText() {
    std::string formattedInput;
    char inputText[MAX_INPUT_LENGTH];
    inputText[0] = '\0';

    // Clear the input area
    clearWindow(inputScreen);
    wrefresh(inputScreen);

    // Move the cursor to the correct location
    mvwprintw(inputScreen, 1, 1, "> ");
    wprintw(inputScreen, "[MORE TEXT, PRESS ENTER]");
    // Get a string of console input
    wgetstr(inputScreen, inputText);
}

