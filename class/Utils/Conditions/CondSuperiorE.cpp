//
// Created by oxabz on 22/04/19.
//

#include "CondSuperiorE.h"
#include "../../GameState.h"

CondSuperiorE::CondSuperiorE(const string &variable1, const string &variable2) {

}

bool CondSuperiorE::checkCondition() {
    return  GameState::getGameVariable(variable1)>=GameState::getGameVariable(variable2);
}
