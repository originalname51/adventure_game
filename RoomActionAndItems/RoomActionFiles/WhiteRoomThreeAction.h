//
// Created by rob on 11/20/16.
//

#ifndef ITEM_TEST_WHITEROOMTHREEACTION_H
#define ITEM_TEST_WHITEROOMTHREEACTION_H


#include "../AbstractRoomAction.h"

class WhiteRoomThreeAction: public AbstractRoomAction {

public:
    WhiteRoomThreeAction(ItemTable *iTable, Command *command);
    WhiteRoomThreeAction(ItemTable *iTable);

private:
    bool discusUsedOnPillar = false;
    ActionResults * Go();
    ActionResults * Use();
    ActionResults * Look();
    ActionResults * Touch();
    ActionResults * Pick();


};

#endif //ITEM_TEST_WHITEROOMTHREEACTION_H
