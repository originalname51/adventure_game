//
// Created by mpalmer on 10/10/2016.
//

#include <string>
#include <vector>

#ifndef FINALADVENTUREPROJECT_MENU_H
#define FINALADVENTUREPROJECT_MENU_H


class Menu {
private:
    std::vector<std::string> options;
public:
    std::vector<std::string> getMenuOptions();
    int displayMenu();
};


#endif //FINALADVENTUREPROJECT_MENU_H
