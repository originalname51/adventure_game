//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_BLUEROOMTHREEACTION_H
#define ITEM_TEST_BLUEROOMTHREEACTION_H


#include "../AbstractRoomAction.h"

class BlueRoomThreeAction : public AbstractRoomAction {

public:
    BlueRoomThreeAction(ItemTable *iTable, Command *command);
    BlueRoomThreeAction(ItemTable *iTable);

private:
    ActionResults * Look();
    ActionResults *   Go();
    ActionResults * Pick();

};


#endif //ITEM_TEST_BLUEROOMTHREEACTION_H
