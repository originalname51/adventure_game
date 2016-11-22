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
    ActionResults  *    Pick();

    bool isDoorOpen(const itemType &key) const;

    bool hasAKey() const;

    void pickUpItem(const itemType &item, std::string &information) const;
};


#endif //ITEM_TEST_THREEKEYROOM_H
