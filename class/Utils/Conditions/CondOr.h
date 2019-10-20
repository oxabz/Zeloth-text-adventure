//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CONDOR_H
#define ZELOTH_CONDOR_H


#include "../Condition.h"

class CondOr : public Condition{
private:
    Condition * condition1;
    Condition * condition2;
public:
    CondOr(Condition *condition1, Condition *condition2);

    bool checkCondition() override ;
};


#endif //ZELOTH_CONDOR_H
