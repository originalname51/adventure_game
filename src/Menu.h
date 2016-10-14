//
// Created by mpalmer on 10/10/2016.
//



#ifndef FINALADVENTUREPROJECT_MENU_H
#define FINALADVENTUREPROJECT_MENU_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Menu {
private:
    std::string options;
public:
    // Default Constructor
    Menu();

    // Preferred Constructor
    Menu(std::string fileName);

    // Public Methods
    std::string getMenuOptions(){return options;}
    bool addMenuOption(std::string newOption);
};


#endif //FINALADVENTUREPROJECT_MENU_H
