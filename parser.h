//
// Created by darkcascadia on 10/16/16.
//

#ifndef PARSER_H
#define PARSER_H

#include <../../boost_1_62_0/boost/tokenizer.hpp>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>

class parser {

public:

    std::string cmd;
    std::string verb;
    std::string subject;
    std::string object;

    parser();
    void setCommandIn(parser parser1, std::string commandIn);
    std::string splitCommand(void);
    void getVerb();
    void getSubject();
    void getObject();
};


#endif //PARSER_H
