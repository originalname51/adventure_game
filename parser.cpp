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
    int validAction = 1;
    int validItem = 1;
    int validObject = 1;

    getVerb();

    for(auto actionIterator = actionMap.begin(); actionIterator != actionMap.end(); ++actionIterator){
        string str = actionIterator->first;
        if(verb != str)
        {
            continue;
        }else{
            validAction = 0;
            break;
        }
    }

    if(validAction == 1){
        return new Command(NO_ACTION,NOTHING);
    }


    if(cmdVector.size() == 1)
    {
        if(verb == "go" || verb == "look" || verb == "examine" || verb == "rest" || verb == "help"){
            act = actionMap.at(verb);
            if((subject.size() != 0)){
                item1 = itemMap.at(subject);
                return new Command(act, item1);
            }
            return new Command(act, NOTHING);
        }

    }else getSubject();

    if(cmdVector.size() <= 0 || verb == "help") {
        return new Command(HELP,SHIH_TZU);
    }

    for(auto itemIterator = itemMap.begin(); itemIterator != itemMap.end(); ++itemIterator){
        string str = itemIterator->first;
        if(subject != str)
        {
            continue;
        }else{
            validItem = 0;
            break;
        }
    }

    if(validItem == 1){
        return new Command(NO_ACTION,NOTHING);
    }

    if((cmdVector.size()) > 2){
        getObject();
        for(auto itemIterator = itemMap.begin(); itemIterator != itemMap.end(); ++itemIterator){
            string str = itemIterator->first;
            if(object != str)
            {
                continue;
            }else{
                validObject = 0;
                break;
            }
        }

        if(validObject == 1){
            return new Command(NO_ACTION,NOTHING);
        }
    }


    act = actionMap.at(verb);
    item1 = itemMap.at(subject);
    if(!(object.empty())){
        if(object == "stairs" || object == "ladder"){
            return new Command(act, item1);
        }
        item2 = itemMap.at(object);
        return new Command(act, item1, item2);
    }else{

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
            {"bluekey", BLUE_KEY},
            {"bucket", BUCKET},
            {"bloodbucket", BLOOD_BUCKET},
            {"cleanbucket", CLEAN_BUCKET},
            {"ladder", LADDER},
            {"door", DOOR_W1},
            {"kid", KID},
            {"basin", BASIN},
            {"box", BOX},
            {"steelbox", BOX},
            {"metalbox", BOX},
            {"glyphs", GLYPHS},
            {"fish", FISH},
            {"babelfish", FISH},
            {"ceiling", CEILING},
            {"ball", BALL},
            {"steelball", BALL},
            {"pipe", PIPE},
            {"tablet", TABLET},
            {"stonetablet", TABLET},
            {"statue", STATUE},
            {"stonestatue", STATUE},
            {"rope", ROPE},
            {"whitepillar", WHITE_PILLAR},
            {"blackpillar", BLACK_PILLAR},
            {"discus", DISCUS},
            {"disc", DISCUS},
            {"powercrystal", POWER_CRYSTAL},
            {"crystal", POWER_CRYSTAL},
            {"torch", TORCH},
            {"lightpillar", LIGHT_PILLAR},
            {"light", LIGHT},
            {"pitcher", PITCHER},
            {"bowl", BOWL},
            {"stonepitcher", PITCHER},
            {"northwall", NORTH_WALL},
            {"eastwall", EAST_WALL},
            {"westwall", WEST_WALL},
            {"backpack", INVENTORY},
            {"stairs", STAIRS}
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
            {"help", HELP},
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
    if(cmdVector[0] == "north" || cmdVector[0] == "south" || cmdVector[0] == "east" || cmdVector[0] == "west" || cmdVector[0] == "ladder" || cmdVector[0] == "stairs"){
        verb = "go";
        subject = cmdVector[0];
        return;
    }

    verb = cmdVector[0];
    return;
}
void parser::getSubject() {

    if(verb == "go"){
        if(cmdVector[1] == "north" || cmdVector[1] == "east" || cmdVector[1] == "west" || cmdVector[1] == "south" || cmdVector[1] == "ladder" || cmdVector[1] == "stairs");
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
        object = cmdVector[3];
        return;
    }else if(cmdVector[2] == "stairs" || cmdVector[2] == "ladder"){
        object = cmdVector[2];
        return;
    }else if(cmdVector[3] == "on") {
        object = cmdVector[4];
        return;
    }
}
