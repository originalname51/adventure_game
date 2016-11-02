//
// Created by Grant on 10/11/2016.
//

#include "parser.h"
using namespace std;

parser::parser() {
    loadActionMap();
    loadItemMap();
//    actions act = NO_ACTION;
//    itemType item1 = NON_EXIST;
//    itemType item2 = NON_EXIST;
    Command command(actions, itemType);
    Command command(actions, itemType, itemType);
};
Command* parser::parse(string commandIn) {

    cmd = stringToLower(commandIn);
    cmdVector = splitCommand();

    getVerb();
    if(cmdVector.size() == 1)
    {
        act = actionMap.at(verb);
        return new Command(act, NOTHING);
    }else getSubject();

    if(cmdVector.size() <= 0 || verb == "help") {
        return new Command(HELP,SHIH_TZU);
    }

    if((cmdVector.size()) > 2)getObject();
    //Test that values have been correctly assigned to command vector
 //   cout << "Below is each element of the command vector:" << endl;
    for(unsigned i = 0; i < cmdVector.size(); ++i){
//        cout << "parser1.cmdVector value[" << i << "]:" << cmdVector[i] << endl;
    }

    act = actionMap.at(verb);
    item1 = itemMap.at(subject);
    if(!(object.empty())){
        item2 = itemMap.at(object);
 //       cout << "item2 value" << item2 << endl;
        return new Command(act, item1, item2);
    }else{
//        cout << "item1 value" << item1 << endl;

        return new Command(act, item1);
    }

}


void parser::loadItemMap() {
    itemMap = {
            {"player", PLAYER},
            {"north", NORTH},
            {"south", SOUTH},
            {"east", EAST},
            {"west", WEST},
            {"nothing", NOTHING},
            {"water", WATER},
            {"shihtzu", SHIH_TZU},
            {"nonexist", NON_EXIST},
            {"foxtoken", FOX_TOKEN},
            {"beantoken", BEAN_TOKEN},
            {"boat", G_BOAT},
            {"goosetoken", GOOSE_TOKEN},
            {"tokendoor", TOKEN_DOOR},
            {"greenkey", GREEN_KEY},
            {"whitekey", WHITE_KEY},
            {"bluekey", BLUE_KEY}

    };
}
void parser::loadActionMap() {
    actionMap = {
            {"go", GO},
            {"throw", THROW},
            {"look", LOOK},
            {"examine", LOOK},
            {"rest", REST},
            {"touch", TOUCH},
            {"pickup", PICK},
            {"pick", PICK},
            {"drop", DROP},
            {"use", USE},
            {"open", OPEN},
            {"close", OPEN},
            {"", NO_ACTION}
    };
}
vector<string> parser::splitCommand() {

    stringstream ss(cmd);
    istream_iterator<std::string> begin(ss);
    istream_iterator<std::string> end;
    vector<string> words(begin, end);
    //std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return words;

}
string parser::stringToLower(string input) {

    for(unsigned i = 0; i < input.length(); i++) {
        if (isupper(input[i])) {
            input[i] = tolower(input[i]);
        }
    }
    //cout << "From inside stringToLower " << input << endl;
    return input;
}
parser::~parser() {
    cout << "Parser deconstruction successful." << endl;
}
void parser::getVerb() {

//    "Valid commands include:\n"
//            "Go, Look, Help, Rest, Touch, Pick-Up\n"
//            "Drop, Use, Open, Close";
//    cout << "Setting verb value to " << cmdVector[0] << endl;
    verb = cmdVector[0];
    return;
}
void parser::getSubject() {

    if(verb == "go"){
        if(cmdVector[1] == "north" || cmdVector[1] == "east" || cmdVector[1] == "west" || cmdVector[1] == "south")
            subject = cmdVector[1];
        return;
    }else if((cmdVector[1] == "at" || cmdVector[1] == "green")) {
                if (cmdVector[2] == "white" || cmdVector[2] == "sticky" || cmdVector[2] == "smelly" || cmdVector[2] == "black") {
                    //setup an ENUM with all of the descriptors (colors, adjectives, etc.)
                    //cout << "setting subject value to " << cmdVector[3] << endl;
                    subject = cmdVector[3];
                    return;
                } else {
                    subject = cmdVector[2];
                    return;
                }
    }else{
        subject = cmdVector[1];
        return;
    }
}
void parser::getObject() {
    if(cmdVector[2] == "")
    {
        object = "";
        return;
    }else if(cmdVector[2] == "on"){
        if (cmdVector[3] == "white" || cmdVector[2] == "sticky" || cmdVector[2] == "smelly" || cmdVector[2] == "black") {
            //setup an ENUM with all of the descriptors (colors, adjectives, etc.)
            //cout << "setting subject value to " << cmdVector[4] << endl;
            object = cmdVector[4];
            return;
        }
        object = cmdVector[3];
        return;
    }else if(cmdVector[3] == "on") {
        if (cmdVector[4] == "white" || cmdVector[2] == "sticky" || cmdVector[2] == "smelly" || cmdVector[2] == "black") {
            //setup an ENUM with all of the descriptors (colors, adjectives, etc.)
            //cout << "setting subject value to " << cmdVector[4] << endl;
            object = cmdVector[5];
            return;
        }
        object = cmdVector[4];
        return;
    }
}
