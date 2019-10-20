//
// Created by oxabz on 22/04/19.
//

#include "CondAnd.h"

bool CondAnd::checkCondition() {
    return condition1->checkCondition()&&condition2->checkCondition();
}

CondAnd::CondAnd(Condition *condition1, Condition *condition2) : condition1(condition1),  condition2(condition2) {

}
