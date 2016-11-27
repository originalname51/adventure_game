//
// Created by rob on 11/19/16.
//

#include "BlueRoomOneAction.h"

BlueRoomOneAction::BlueRoomOneAction(ItemTable *iTable, Command *command) : AbstractRoomAction(iTable, command) {}
BlueRoomOneAction::BlueRoomOneAction(ItemTable *iTable) : AbstractRoomAction(iTable) {}

ActionResults *BlueRoomOneAction::Look() {
    if (commands->getMainItem() == TORCH) {
        itemList->getValue(TORCH)->setLocation(W_ROOM1);
        return new ActionResults(CURRENT, "One of the glass cases appears to be missing a back panel."
                "You think you might be able to get a torch.");
    }
    return AbstractRoomAction::Look();
}

ActionResults * BlueRoomOneAction::Pick() {
    if(commands->getMainItem() == TORCH && itemList->getValue(TORCH)->getLocation() == BACKPACK){
        return new ActionResults(CURRENT, "You already have a torch. You double check that you haven't dropped it and are extremely releived.");
    }else if(commands->getMainItem() == TORCH){
        itemList->getValue(TORCH)->setLocation(BACKPACK);
        return new ActionResults(CURRENT, "You grab the torch from the box missing a panel and hold on to it. You feel confident, almost as if you should try opening the door.");
    } else {
        return AbstractRoomAction::Pick();
    }
}

ActionResults * BlueRoomOneAction::Drop() {
    if(commands->getMainItem() == TORCH && itemList->getValue(TORCH)->getLocation() == BACKPACK){
        itemList->getValue(TORCH)->setLocation(B_ROOM1);
        return new ActionResults(CURRENT, "Against your better judgement, you drop the torch to the ground. It lays at your feet looking abandoned.");
    } else {
        return AbstractRoomAction::Drop();
    }
}

ActionResults * BlueRoomOneAction::Touch(){
    if(commands->getMainItem() == TORCH && itemList->getValue(TORCH)->getLocation() == BACKPACK) {
        return new ActionResults(CURRENT, "You reassure yourself that the torch is indeed in your pack.");
    } else if(commands->getMainItem() == TORCH){
        return new ActionResults(CURRENT, "The torch feels very rough, but smells like it will burn well.");
    } else if(commands->getMainItem() == DOOR_W1 && itemList->getValue(TORCH)->getLocation() == BACKPACK){
        return new ActionResults(CURRENT, "The door seems to be unlocked. You could probably open it if you wanted to.");
    } else if(commands->getMainItem() == DOOR_W1){
        return new ActionResults(CURRENT, "Seems door-ish. You don't seem insulted at this, but you give the door a knowing look just the same.");
    } else {
        return AbstractRoomAction::Look();
    }
}

ActionResults * BlueRoomOneAction::Open() {
    if(commands->getMainItem() == DOOR_W1) {
        itemList->getValue(STAIRS)->setLocation(B_ROOM1);
        return new ActionResults(CURRENT, "You reach for the door and attempt to slide it open. Your attempt is successful. Some stairs are revealed when you open the door.");
    } else {
        return AbstractRoomAction::Open();
    }
}


ActionResults * BlueRoomOneAction::Go() {

    if(commands->getMainItem() == NORTH && itemList->getValue(STAIRS)->getLocation() == B_ROOM1){
        return new ActionResults(B_ROOM2, "You head down the stairs to the North. Seems to be getting colder.");
    }

    if (commands->getMainItem() == NORTH) {
        return new ActionResults(CURRENT, "The door seems closed pretty firmly and you can't phaseshift, maybe try opening it?");
    }
    if (commands->getMainItem() == SOUTH) {
        return new ActionResults(CURRENT, "You can't go back through the door. It's locked. You must find a new way out.");
    }
    if (commands->getMainItem() == EAST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south...");
    }
    if (commands->getMainItem() == WEST) {
        return new ActionResults(CURRENT, "You can't go west, you can only go south...");
    }
    if (commands->getMainItem() == STAIRS && itemList->getValue(STAIRS)->getLocation() == B_ROOM1) {
        return new ActionResults(B_ROOM2, "You head down the stairs to the North. Seems to be getting colder.");
    }
    if (commands->getMainItem() == STAIRS && itemList->getValue(STAIRS)->getLocation() == HIDDEN) {
        return new ActionResults(CURRENT, "No stairs are currently visible.");
    }
    return new ActionResults(CURRENT,"You can't go there.");

}