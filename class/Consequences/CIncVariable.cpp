//
// Created by oxabz on 22/04/19.
//

#include "CIncVariable.h"
#include "../GameState.h"

CIncVariable::CIncVariable(const string &variable, double value) : variable(variable), value(value) {

}

void CIncVariable::doConsequence() {
    GameState::incGameVariable(variable,value);
}
