//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_WHITEROOMONEACTION_H
#define ITEM_TEST_WHITEROOMONEACTION_H


#include "../AbstractRoomAction.h"

class WhiteRoomOneAction : public AbstractRoomAction {

public:
    WhiteRoomOneAction(ItemTable *iTable, Command *command);
    WhiteRoomOneAction(ItemTable *iTable);

private:
    ActionResults * Go();
    ActionResults * Use();
};


#endif //ITEM_TEST_WHITEROOMONEACTION_H
