//
// Created by oxabz on 22/04/19.
//

#include "CChangeVariable.h"
#include "../GameState.h"

CChangeVariable::CChangeVariable(const string &variable, double value) : variable(variable), value(value) {}

void CChangeVariable::doConsequence() {
    GameState::setGameVariable(variable,value);
}
