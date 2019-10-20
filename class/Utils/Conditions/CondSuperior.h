//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CONDSUPERIOR_H
#define ZELOTH_CONDSUPERIOR_H

#include <string>

using namespace std;

#include "../Condition.h"

class CondSuperior : public Condition{
private:
    string variable1;
    string variable2;
public:
    CondSuperior(const string &variable1, const string &variable2);

    bool checkCondition() override ;
};


#endif //ZELOTH_CONDSUPERIOR_H
