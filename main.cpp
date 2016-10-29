#include <iostream>
#include "Rooms/Room.h"
#include "Rooms/StartRoom.h"
#include "Rooms/KeyRoom.h"
#include "parser.h"

int main() {

    int endGame = 1;
    ItemTable table = ItemTable();
    Room *r = new KeyRoom("keyroom", &table, false);
    cout << endl << r->getDescription()<< endl;


    //Enter the menu screen/graphics loop here
    while(endGame != 0)
    {
        //Graphics passes string object to parser
        parser *commandObj = new parser;
        //This is where we'll get the string from Matt's console
        //Replace string with object from console
        std::string commandIn("look at white pillar");

        cout << "Testing parser values before and after..." << endl;
        cout << "Command in main function: " << commandIn << endl;
        commandObj->parse(commandObj, commandIn);

        //Test that values have been correctly assigned to command vector
        cout << "Below is each element of the command vector:" << endl;
        for(unsigned i = 0; i < commandObj->cmdVector.size(); ++i){
            cout << "parser1.cmdVector value[" << i << "]:" << commandObj->cmdVector[i] << endl;
        }
        cout << "commandObj->verb: " << commandObj->verb << endl;
        cout << "commandObj->subject: " << commandObj->subject << endl;
        cout << "commandObj->object: " << commandObj->object << endl;
        //Parser passes 2 or 3 tuple to Room Action


        //Items get updated

        //Loop back to beginning for next user command
        endGame = endGame - 1;
        //If no value for command verb (when user enters blank command or "HELP", start next iteration
        if(commandObj->verb == "help"){
            continue;
        }

        free (commandObj);
    }


    free (r);

    return 0;
}