//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ACTIONRESULTS_H
#define FINALADVENTUREPROJECT_ACTIONRESULTS_H
#include <iostream>


class ActionResults {
private:
    const std::string room;
public:
    ActionResults(std::string r) : room(r){};
    const std::string getRoom(){return room;};
};
#endif //FINALADVENTUREPROJECT_ACTIONRESULTS_H
