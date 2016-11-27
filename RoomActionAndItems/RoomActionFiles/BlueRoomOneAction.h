//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_BLUEROOMONEACTION_H
#define ITEM_TEST_BLUEROOMONEACTION_H


#include "../AbstractRoomAction.h"

class BlueRoomOneAction : public AbstractRoomAction {
public:
    BlueRoomOneAction(ItemTable *iTable, Command *command);
    BlueRoomOneAction(ItemTable *iTable);

private:
    ActionResults * Look();
    ActionResults * Touch();
    ActionResults * Go();
    ActionResults * Drop();
    ActionResults * Open();
    ActionResults * Pick();
};


#endif //ITEM_TEST_BLUEROOMONEACTION_H
