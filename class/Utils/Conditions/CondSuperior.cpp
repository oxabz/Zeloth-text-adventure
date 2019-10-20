//
// Created by oxabz on 22/04/19.
//

#include "CondSuperior.h"
#include "../../GameState.h"

CondSuperior::CondSuperior(const string &variable1, const string &variable2) : variable1(variable1),
                                                                               variable2(variable2) {}

bool CondSuperior::checkCondition() {
    return GameState::getGameVariable(variable1)>GameState::getGameVariable(variable2);
}
