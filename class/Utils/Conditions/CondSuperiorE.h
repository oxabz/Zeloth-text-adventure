//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CONDSUPERIORE_H
#define ZELOTH_CONDSUPERIORE_H

#include <string>

using namespace std;

#include "../Condition.h"

class CondSuperiorE : public Condition {
private:
    string variable1;
    string variable2;
public:
    CondSuperiorE(const string &variable1, const string &variable2);

    bool checkCondition() override ;
};


#endif //ZELOTH_CONDSUPERIORE_H
