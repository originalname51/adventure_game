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
    ActionResults * Use();
    ActionResults * Touch();
    ActionResults * Go();
    ActionResults * Pick();
    ActionResults * Drop();
    ActionResults * Throw();

};


#endif //ITEM_TEST_WHITEROOMONEACTION_H
