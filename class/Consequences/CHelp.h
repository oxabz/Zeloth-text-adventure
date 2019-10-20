//
// Created by oxabz on 25/04/19.
//

#ifndef ZELOTH_CHELP_H
#define ZELOTH_CHELP_H


#include "../Consequence.h"

class Event;

class CHelp : public Consequence {
private:
    Event* event;
public:
    CHelp(Event *event);

    void doConsequence() override ;
};


#endif //ZELOTH_CHELP_H
