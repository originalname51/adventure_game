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
using namespace std;

class parser {

public:

    string cmd;
    string verb;
    string subject;
    string object;
    vector<string> cmdVector;

    parser();
    ~parser();
    void parse(parser *parser1, std::string commandIn);
    vector<string> splitCommand(parser *parser1);
    string stringToLower(string input);
    void getVerb();
    void getSubject();
    void getObject();
};


#endif //PARSER_H
