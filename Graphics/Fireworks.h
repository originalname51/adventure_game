//
// Created by mpalmer on 11/8/2016.
//

#ifndef FIREWORKS_H
#define FIREWORKS_H


#include <string>
#include <vector>
#include "Animation.h"
#include "AnimationsSubClasses/Firework.h"


class Fireworks : public Animation {
private:

public:
    // Public Methods
    bool displayAnimation(Screen &screen);
};


#endif //ITEM_TEST_FIREWORKS_H
