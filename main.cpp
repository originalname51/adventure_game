// Comment this line out to turn off debugging
#define DEBUG 1


// Debugging includes
#ifdef DEBUG
#include <iostream>
#endif


// Internal Class includes
#include "Rooms/Room.h"
#include "Rooms/StartRoom.h"
#include "Rooms/KeyRoom.h"
#include "parser.h"
#include "Graphics/Graphics.h"



int main(int argc, char *argv[]) {
    // Initialize the screen with beginning values
    std::string startRoom = "keyroom";
    std::string input = "";
    Graphics graphics(0, startRoom);


    // DEBUGGING Initialization Code
    #ifdef DEBUG
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
    #endif  // DEBUG

    // Display Game Title animation
    graphics.animation(std::string("GameTitle"));

    // Display beginning text prompt
    graphics.displayText(std::string("This is the example text displayed by the beginning room"));

    //Enter the menu screen/graphics loop here
    while(endGame != 0)
    {
        #ifdef DEBUG
        input = graphics.getInput();

        graphics.displayText(std::string("Whoa, you entered: ") + input);

        endGame = endGame - 1;

        graphics.setScore(1+1);
        graphics.setRoom(std::string("The New Room"));
        #else


        //Graphics passes string object to parser

        // Example parser.parse(parser, graphics.getInput);

        //Parser passes 2 or 3 tuple to Room Action

        //Items get updated

        //Loop back to beginning for next user command

        // The response to the command is printed

        #endif  // DEBUG
    }

    #ifdef DEBUG
    free (r);
    free (commandObj);
    #endif  // DEBUG

    return 0;
}