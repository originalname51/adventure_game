//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_WHITEROOMFIVEACTION_H
#define ITEM_TEST_WHITEROOMFIVEACTION_H


#include "../AbstractRoomAction.h"

class WhiteRoomFiveAction   : public AbstractRoomAction {

public:
    WhiteRoomFiveAction(ItemTable *iTable, Command *command);
    WhiteRoomFiveAction(ItemTable *iTable);

private:
    bool roomWon = false;
    ActionResults * Go();
    ActionResults * Use();
    ActionResults * Look();
    ActionResults * Pick();

};


#endif //ITEM_TEST_WHITEROOMFIVEACTION_H
