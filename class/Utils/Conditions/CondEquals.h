//
// Created by oxabz on 23/04/19.
//

#ifndef ZELOTH_CONDEQUALS_H
#define ZELOTH_CONDEQUALS_H

#include <string>

using std::string;

#include "../Condition.h"

class CondEquals : public Condition{
private:
    string variable1;
    string variable2;
public:
    CondEquals(const string &variable1, const string &variable2);

    bool checkCondition() override ;
};


#endif //ZELOTH_CONDEQUALS_H
