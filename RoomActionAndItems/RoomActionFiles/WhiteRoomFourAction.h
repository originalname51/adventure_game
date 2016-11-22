//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_WHITEROOMFOURACTION_H
#define ITEM_TEST_WHITEROOMFOURACTION_H


#include "../AbstractRoomAction.h"

class WhiteRoomFourAction  : public AbstractRoomAction {

public:
    WhiteRoomFourAction(ItemTable *iTable, Command *command);
    WhiteRoomFourAction(ItemTable *iTable);

private:
    ActionResults * Go();
    ActionResults * Action();
    ActionResults * Drop();
    ActionResults * Pick();
    ActionResults * Throw();
};


#endif //ITEM_TEST_WHITEROOMFOURACTION_H
