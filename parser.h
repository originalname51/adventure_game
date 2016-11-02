//
// Created by darkcascadia on 10/16/16.
//

#ifndef PARSER_H
#define PARSER_H


//#include <../../boost_1_62_0/boost/tokenizer.hpp>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include "Command.h"
#include "ItemsAndActions/Action.h"

using namespace std;

class parser {

public:

    actions act;
    itemType item1;
    itemType item2;
    string cmd;
    string verb;
    string subject;
    string object;
    vector<string> cmdVector;


    //Initial constructor and destructor
    parser();
    ~parser();



    //Parse a string object passed in from the console
    Command* parse(std::string commandIn);

    //Get each piece of the command
    void getVerb();
    void getSubject();
    void getObject();


private:

    std::map< string, actions > actionMap;
    std::map< string, itemType > itemMap;
    void loadItemMap();
    void loadActionMap();
    vector<string> splitCommand();
    string stringToLower(string input);
};


#endif //PARSER_H
