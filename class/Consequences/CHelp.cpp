//
// Created by oxabz on 25/04/19.
//

#include "CHelp.h"

#include "../Event.h"
#include "../Utils/DisplayUtils.h"

CHelp::CHelp(Event *event) : event(event) {}

void CHelp::doConsequence() {
    vector<string> commands = event->getCommands();
    DisplayUtils::DisplayText("Available action : ");
    for (int i = 0; i < commands.size(); ++i) {
        DisplayUtils::DisplayText('\t'+commands[i]);
    }
}
