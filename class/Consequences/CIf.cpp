//
// Created by oxabz on 22/04/19.
//

#include "CIf.h"

#include "../Utils/Condition.h"

void CIf::doConsequence() {
    if(condition->checkCondition()){
        for (int i = 0; i < consequences.size(); ++i) {
            consequences[i]->doConsequence();
        }
    }

}

CIf::CIf(Condition *condition) : condition(condition) {}

void CIf::addConsequence(Consequence *consequence) {
    consequences.emplace_back(consequence);
}
