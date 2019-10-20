//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CIF_H
#define ZELOTH_CIF_H

#include <vector>
#include "../Consequence.h"

using std::vector;

class Condition;

class CIf : public Consequence{
private:
    Condition * condition;
    vector<Consequence *> consequences;
public:
    CIf(Condition *condition);

    void doConsequence() override ;

    void addConsequence(Consequence * consequence);
};


#endif //ZELOTH_CIF_H
