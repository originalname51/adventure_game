//
// Created by rob on 10/29/16.
//

#ifndef ITEM_TEST_THREEKEYROOM_H
#define ITEM_TEST_THREEKEYROOM_H


#include "../AbstractRoomAction.h"

class ThreeKeyRoomAction : public AbstractRoomAction{

public:
    ThreeKeyRoomAction(ItemTable *iList, Command *commands);
    ThreeKeyRoomAction(ItemTable *iList);

private:
    ActionResults  *   Throw();
    ActionResults  *      Go();
    ActionResults  *    Look();
    ActionResults  *    Rest();
    ActionResults  *   Touch();
    ActionResults  *    Pick();
    ActionResults  *    Drop();
    ActionResults  *     Use();
    ActionResults  *    Open();
    ActionResults  *   Close();
//    ActionResults  * Nothing();

    bool isDoorOpen(const itemType &key) const;
};


#endif //ITEM_TEST_THREEKEYROOM_H
