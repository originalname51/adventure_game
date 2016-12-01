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
    ActionResults * Use();
    ActionResults * Pick();
    ActionResults * Throw();
    ActionResults * Drop();
    ActionResults * Rest();

};


#endif //ITEM_TEST_BLUEROOMTHREEACTION_H
