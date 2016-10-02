//
// Created by rob on 10/1/16.
//

#include "Action.h"
Action::Action(actions a) : act(a){};

actions Action::getAction() {
    return act;
}