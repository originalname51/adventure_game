//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_BLUEROOMTWOACTION_H
#define ITEM_TEST_BLUEROOMTWOACTION_H


#include "../AbstractRoomAction.h"

class BlueRoomTwoAction : public AbstractRoomAction {

public:
    BlueRoomTwoAction(ItemTable *iTable, Command *command);
    BlueRoomTwoAction(ItemTable *iTable);

private:
    ActionResults * Look();
    ActionResults * Go();
    ActionResults * Drop();
    ActionResults * Pick();

};

#endif //ITEM_TEST_BLUEROOMTWOACTION_H
