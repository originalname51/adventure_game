//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ACTION_H
#define FINALADVENTUREPROJECT_ACTION_H

enum actions { NORTH, THROW };

class Action {
private:
    actions act;
public:
    Action(actions a);
    actions getAction();
};


#endif //FINALADVENTUREPROJECT_ACTION_H
