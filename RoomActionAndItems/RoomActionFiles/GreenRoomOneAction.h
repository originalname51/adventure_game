//
// Created by rob on 10/10/16.
//

#ifndef ITEM_TEST_KEYROOMACTION_H
#define ITEM_TEST_KEYROOMACTION_H

#include "../ActionResults.h"
#include "../../Command.h"
#include "../AbstractRoomAction.h"

class GreenRoomOneAction: public AbstractRoomAction {

public:
    GreenRoomOneAction(ItemTable *iList, Command *commands);
    GreenRoomOneAction(ItemTable *iList);

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
    ActionResults  * Nothing();

    bool getIsGooseHere() const;

    bool isBeanToken() const;

    bool itemInRoom(itemType item) const;

    bool hasAToken() const;

    bool foxEatsGoose() const;

    bool gooseEatsBean() const;

    void resetTokens() const;

    void takeBoat() const;

    void dropItem(const itemType &item) const;
};


#endif //ITEM_TEST_KEYROOMACTION_H
