//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_GREENROOMTHREEACTION_H
#define ITEM_TEST_GREENROOMTHREEACTION_H


#include "../AbstractRoomAction.h"

class GreenRoomThreeAction : public AbstractRoomAction {
public:
    GreenRoomThreeAction(ItemTable *iTable, Command *command);
    GreenRoomThreeAction(ItemTable *iList);

private:
    ActionResults * Use();
    ActionResults * Go();
};


#endif //ITEM_TEST_GREENROOMTHREEACTION_H
