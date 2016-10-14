//
// Created by mpalmer on 10/10/2016.
//

#include "Menu.h"

bool Menu::addMenuOption(std::string newOption) {
    options += newOption + "\n";
    return true;
}

Menu::Menu() {
    options = "No menu items submitted.";
}


Menu::Menu(std::string fileName) {
    // Open the file for reading
    std::ifstream inputFile;

    inputFile.open(fileName);

    std::string input = "";

    // Read each line of the file into the menu option string

    if(inputFile){
        while( std::getline(inputFile, input, '\n') ){
            options.append(input);
            options.append("\n");
        }
        inputFile.close();
    }
    else {
        options = "Nothing was loaded.";
    }
}


