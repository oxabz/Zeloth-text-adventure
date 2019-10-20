//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CDISPLAYTEXT_H
#define ZELOTH_CDISPLAYTEXT_H

#include <string>

using std::string;

#include "../Consequence.h"

class CDisplayText : public Consequence{
private:
    string text;
public:
    CDisplayText(const string &text);

    void doConsequence() override ;
};


#endif //ZELOTH_CDISPLAYTEXT_H
