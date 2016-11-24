//
// Created by rob on 10/10/16.
//

#ifndef ITEM_TEST_KEYROOMACTION_H
#define ITEM_TEST_KEYROOMACTION_H

#include "../ActionResults.h"
#include "../../Command.h"
#include "../AbstractRoomAction.h"

class GreenRoomOneAction : public AbstractRoomAction {

public:
    GreenRoomOneAction(ItemTable *iList, Command *commands);
    GreenRoomOneAction(ItemTable *iList);

private:
    ActionResults  *      Go();
    ActionResults  *     Use();
    ActionResults  * Nothing();

    bool foxEatsGoose() const;

    bool gooseEatsBean() const;

    void resetTokens() const;

    void takeBoat() const;

    bool isRoomWon() const;
};


#endif //ITEM_TEST_KEYROOMACTION_H
