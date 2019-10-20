//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_SITUATION_H
#define ZELOTH_SITUATION_H

#include <string>

using std::string;

class Condition;

class Situation {
private:
    string text;
public:
    Situation(const string &text);

    string getSituation();
};


#endif //ZELOTH_SITUATION_H
