//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CCHANGEVARIABLE_H
#define ZELOTH_CCHANGEVARIABLE_H

#include <string>
#include "../Consequence.h"

using std::string;

class CChangeVariable: public Consequence {
private:
    string variable;
    double value;
public:
    CChangeVariable(const string &variable, double value);

    void doConsequence() override ;
};


#endif //ZELOTH_CCHANGEVARIABLE_H
