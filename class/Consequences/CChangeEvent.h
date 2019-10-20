//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_CCHANGEEVENT_H
#define ZELOTH_CCHANGEEVENT_H


#include "../Consequence.h"


class CChangeEvent : public Consequence {
private:
    int id;
public:
    CChangeEvent(int id);
    void doConsequence() override ;
};


#endif //ZELOTH_CCHANGEEVENT_H
