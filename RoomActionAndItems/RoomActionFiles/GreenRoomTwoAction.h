//
// Created by rob on 10/30/16.
//

#ifndef ITEM_TEST_GREENROOMTWOACTION_H
#define ITEM_TEST_GREENROOMTWOACTION_H

#include "../../Command.h"
#include "../AbstractRoomAction.h"
class GreenRoomTwoAction : public AbstractRoomAction {

public:
    GreenRoomTwoAction(ItemTable *iList, Command *commands);
    GreenRoomTwoAction(ItemTable *iList);

private:
    ActionResults  *      Go();


};


#endif //ITEM_TEST_GREENROOMTWOACTION_H
