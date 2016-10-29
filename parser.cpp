//
// Created by Grant on 10/11/2016.
//

#include "parser.h"
using namespace std;

void parser::parse(parser *parser1, string commandIn) {

    parser1->cmd = parser1->stringToLower(commandIn);

    parser1->cmdVector = parser1->splitCommand(parser1);

    parser1->getVerb(parser1);
    parser1->getSubject(parser1);
    if((parser1->cmdVector.size()) > 2)parser1->getObject(parser1);

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

}

void parser::getSubject(parser *parser1) {

}

void parser::getObject(parser *parser1) {

};

