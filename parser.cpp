//
// Created by Grant on 10/11/2016.
//

#include "parser.h"


void parser::setCommandIn(parser parser1, std::string commandIn) {
    parser1.cmd = commandIn;
    std::cout << "Command recorded: " << parser1.cmd << std::endl;
}

parser::parser(){};

