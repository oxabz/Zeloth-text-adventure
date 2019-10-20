//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CONDAND_H
#define ZELOTH_CONDAND_H


#include "../Condition.h"

class CondAnd : public Condition {
private:
    Condition * condition1;
    Condition * condition2;
public:
    CondAnd(Condition *condition1,Condition *condition2);

    bool checkCondition() override ;
};


#endif //ZELOTH_CONDAND_H
