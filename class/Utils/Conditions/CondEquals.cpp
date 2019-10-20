//
// Created by oxabz on 23/04/19.
//

#include "CondEquals.h"
#include "../../GameState.h"

CondEquals::CondEquals(const string &variable1, const string &variable2) : variable1(variable1), variable2(variable2){

}

bool CondEquals::checkCondition() {
    return GameState::getGameVariable(variable1)==GameState::getGameVariable(variable2);
}
