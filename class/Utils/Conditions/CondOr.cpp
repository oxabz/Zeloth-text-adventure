//
// Created by oxabz on 22/04/19.
//

#include "CondOr.h"

CondOr::CondOr(Condition *condition1, Condition *condition2) : condition1(condition1), condition2(condition2) {}

bool CondOr::checkCondition() {
    return condition1->checkCondition()||condition2->checkCondition();
}
