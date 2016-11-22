//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_BLUEROOMFIVEACTION_H
#define ITEM_TEST_BLUEROOMFIVEACTION_H


#include "../AbstractRoomAction.h"

class BlueRoomFiveAction : public AbstractRoomAction {
public:
    BlueRoomFiveAction(ItemTable *iTable, Command *command);
    BlueRoomFiveAction(ItemTable *iTable);

private:
    bool torchUsed = false;
    ActionResults * Action();
    ActionResults *  Look();
    ActionResults *    Go();
    ActionResults *   Use();
    ActionResults *   Open();
    ActionResults *   Pick();
    ActionResults *   Drop();


};


#endif //ITEM_TEST_BLUEROOMFIVEACTION_H
