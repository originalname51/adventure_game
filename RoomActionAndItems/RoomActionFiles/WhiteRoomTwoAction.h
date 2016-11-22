//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_WHITEROOMTWOACTION_H
#define ITEM_TEST_WHITEROOMTWOACTION_H


#include "../AbstractRoomAction.h"

class WhiteRoomTwoAction : public AbstractRoomAction {

public:
    WhiteRoomTwoAction(ItemTable *iTable, Command *command);
    WhiteRoomTwoAction(ItemTable *iTable);

private:
    bool roomLit = false;
    bool eastWallRead = false;
    bool westWallRead = false;
    bool northWallRead = false;
    ActionResults * Go();
    ActionResults * Use();
    ActionResults * Look();
    ActionResults * Pick();
    ActionResults * Drop();
    ActionResults * Rest();
};



#endif //ITEM_TEST_WHITEROOMTWOACTION_H
