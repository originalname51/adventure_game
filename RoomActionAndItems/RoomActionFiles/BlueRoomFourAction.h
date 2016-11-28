//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_BLUEROOMFOURACTION_H
#define ITEM_TEST_BLUEROOMFOURACTION_H


#include "../AbstractRoomAction.h"

class BlueRoomFourAction : public AbstractRoomAction {
public:
    BlueRoomFourAction(ItemTable *iTable, Command *command);
    BlueRoomFourAction(ItemTable *iTable);

private:
    bool whitePillarRope = false;
    bool blackPillarRope = false;
    ActionResults * Look();
    ActionResults *   Go();
    ActionResults * Pick();
    ActionResults *  Use();
    ActionResults * Throw();

};

#endif //ITEM_TEST_BLUEROOMFOURACTION_H
