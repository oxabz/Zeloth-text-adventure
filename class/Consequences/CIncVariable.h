//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CINCVARIABLE_H
#define ZELOTH_CINCVARIABLE_H

#include <string>
#include "../Consequence.h"

using std::string;

class CIncVariable : public Consequence{
private:
    string variable;
    double value;
public:
    CIncVariable(const string &variable, double value);

    void doConsequence() override ;
};


#endif //ZELOTH_CINCVARIABLE_H
