//
// Created by rob on 10/1/16.
//

#ifndef FINALADVENTUREPROJECT_ACTION_H
#define FINALADVENTUREPROJECT_ACTION_H
enum actions { GO, THROW, LOOK, REST, TOUCH, PICK, DROP, USE, OPEN, CLOSE, NO_ACTION };

class Action {
private:
    const actions act;
public:
    Action(actions a);
    actions getAction();
};


#endif //FINALADVENTUREPROJECT_ACTION_H
