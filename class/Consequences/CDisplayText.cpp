//
// Created by oxabz on 22/04/19.
//

#include "CDisplayText.h"
#include "../Utils/DisplayUtils.h"

CDisplayText::CDisplayText(const string &text) : text(text) {}

void CDisplayText::doConsequence() {
    DisplayUtils::DisplayText(text);
}
