//
// Created by Grant on 10/11/2016.
//

#include "parser.h"
using namespace std;

void parser::parse(parser *parser1, string commandIn) {

    parser1->cmd = parser1->stringToLower(commandIn);

    parser1->cmdVector = parser1->splitCommand(parser1);

    parser1->getVerb(parser1);

    if(parser1->cmdVector.size() <= 0 || parser1->verb == "help") {
        parser1->printHelp();
        parser1->verb = "help";
    }


    parser1->getSubject(parser1);
    if((parser1->cmdVector.size()) > 2)parser1->getObject(parser1);

    return;
}

parser::parser(){};

vector<string> parser::splitCommand(parser *parser1) {

    stringstream ss(parser1->cmd);
    istream_iterator<std::string> begin(ss);
    istream_iterator<std::string> end;
    vector<string> words(begin, end);
    //std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return words;

}
string parser::stringToLower(string input) {

    for(unsigned i = 0; i < input.length(); i++) {
        if (isupper(input[i])) {
            input[i] = tolower(input.at(i));
        }
    }
    //cout << "From inside stringToLower " << input << endl;
    return input;
}
parser::~parser() {
    cout << "Parser deconstruction successful." << endl;
}
void parser::getVerb(parser *parser1) {

//    "Valid commands include:\n"
//            "Go, Look, Help, Rest, Touch, Pick-Up\n"
//            "Drop, Use, Open, Close";
    string verb;
    cout << "Setting verb value to " << parser1->cmdVector[0] << endl;
    parser1->verb = parser1->cmdVector[0];

    return;
}
void parser::getSubject(parser *parser1) {

    if(parser1->verb == "go"){
        if(parser1->cmdVector[1] == "north" || parser1->cmdVector[1] == "east" || parser1->cmdVector[1] == "west" || parser1->cmdVector[1] == "south")
            parser1->subject = parser1->cmdVector[1];
        return;
    }else if((cmdVector[1] == "at")) {
        if (cmdVector[2] == "white" || cmdVector[2] == "sticky" || cmdVector[2] == "smelly" || cmdVector[2] == "black") {
            //setup an ENUM with all of the descriptors (colors, adjectives, etc.)
            cout << "setting subject value to " << cmdVector[3] << endl;
            parser1->subject = parser1->cmdVector[3];
            return;
        } else {
            parser1->subject = cmdVector[2];
            return;
        }
    }else{
        parser1->subject = cmdVector[1];
        return;
    }
}
void parser::getObject(parser *parser1) {
    if(parser1->cmdVector[2] == "")
    {
        parser1->object = "";
        return;
    }else if(parser1->cmdVector[2] == "on"){
        if (cmdVector[3] == "white" || cmdVector[2] == "sticky" || cmdVector[2] == "smelly" || cmdVector[2] == "black") {
            //setup an ENUM with all of the descriptors (colors, adjectives, etc.)
            cout << "setting subject value to " << cmdVector[4] << endl;
            parser1->object = cmdVector[4];
            return;
        }
        parser1->object = parser1->cmdVector[3];
        return;
    }else if(parser1->cmdVector[3] == "on") {
        if (cmdVector[4] == "white" || cmdVector[2] == "sticky" || cmdVector[2] == "smelly" || cmdVector[2] == "black") {
            //setup an ENUM with all of the descriptors (colors, adjectives, etc.)
            cout << "setting subject value to " << cmdVector[4] << endl;
            parser1->object = cmdVector[5];
            return;
        }
        parser1->object = parser1->cmdVector[4];
        return;
    }
}
void parser::printHelp() {
    cout << "Command options and structure" << endl
         << "_________________________________________________" << endl
         << "GO _____ | ex: GO NORTH" << endl
         << "=> takes you to the next room in that direction." << endl
         << "LOOK (or) EXAMINE _____ | ex: LOOK TABLE" << endl
         << "=> examines an item/object/feature more closely" << endl
         << "TOUCH ____ | ex: TOUCH STONE" << endl
         << "=> Interacts with an item/object/feature" << endl
         << "PICKUP (or) TAKE ____ | ex: PICKUP STATUE" << endl
         << "=> attempts to put an item into your inventory" << endl
         << "DROP _____ | ex: DROP PAMPHLET" << endl
         << "=> drops an item from your inventory to the floor" << endl
         << "USE _____ | ex: USE ROPE" << endl
         << "=> uses an item in a way that you deem natural." << endl
         << "OPEN _____ | ex: OPEN DOOR" << endl
         << "=> Attempts to open an item/object/feature" << endl
         << "CLOSE _____ | ex: CLOSE DOOR" << endl
         << "=> Attempts to close an item/object/feature" << endl
         << "HELP | ex: [Blank] or HELP" << endl
         << "=> Pretty sure you know what this one does..." << endl
         << endl;
    return;
}
