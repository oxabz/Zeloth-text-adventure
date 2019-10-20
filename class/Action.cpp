//
// Created by oxabz on 22/04/19.
//

#include "Action.h"
#include "Consequence.h"

Action::Action(const string &command) : command(command) {}

void Action::addConsequence(Consequence *consequence) {
    consequences.emplace_back(consequence);
}

void Action::doAction() {
    for (int i = 0; i < consequences.size(); ++i) {
        consequences[i]->doConsequence();
    }
}

const string &Action::getCommand() const {
    return command;
}

void Action::setCommand(const string &command) {
    Action::command = command;
}
