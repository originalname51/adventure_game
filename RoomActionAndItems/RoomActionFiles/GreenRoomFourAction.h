//
// Created by rob on 11/19/16.
//

#ifndef ITEM_TEST_GREENROOMFOURACTION_H
#define ITEM_TEST_GREENROOMFOURACTION_H


#include "../AbstractRoomAction.h"

class GreenRoomFourAction : public AbstractRoomAction {
public:
    GreenRoomFourAction(ItemTable *iTable);
    GreenRoomFourAction(ItemTable *iTable, Command *command);

private:
    ActionResults * Use();

    ActionResults *Go();
};


#endif //ITEM_TEST_GREENROOMFOURACTION_H
