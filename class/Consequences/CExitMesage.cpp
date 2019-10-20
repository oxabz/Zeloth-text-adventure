//
// Created by oxabz on 22/04/19.
//

#include "CExitMesage.h"
#include "../GameState.h"

void CExitMesage::doConsequence() {
    GameState::setExit(true);
}

CExitMesage::CExitMesage() = default;
