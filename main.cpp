#include <iostream>
#include "Rooms/Room.h"
#include "Rooms/StartRoom.h"
#include "Rooms/KeyRoom.h"
#include "parser.h"

int main() {

    int endGame = 10;
    ItemTable table = ItemTable();
    Room *r = new KeyRoom("keyroom", &table, false);
    cout << endl << r->getDescription()<< endl;

    parser *commandObj = new parser;
    std::string commandIn("use rope on white pillar");

    cout << "Testing parser values before and after..." << endl;
    cout << "Command in main function: " << commandIn << endl;
    commandObj->parse(commandObj, commandIn);

    //Test that values have been correctly assigned to command vector
    cout << "commandObj.cmd value: " << commandObj->cmd << endl;
    cout << "Below is each element of the command vector:" << endl;
    for(unsigned i = 0; i < commandObj->cmdVector.size(); ++i){
        cout << "parser1.cmdVector value[" << i << "]:" << commandObj->cmdVector[i] << endl;
    }

    //Enter the menu screen/graphics loop here
    while(endGame != 0)
    {
        //Graphics passes string object to parser

        //Parser passes 2 or 3 tuple to Room Action

        //Items get updated

        //Loop back to beginning for next user command
        endGame = endGame - 1;
    }


    free (r);
    free (commandObj);
    return 0;
}