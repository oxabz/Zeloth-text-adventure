//
// Created by oxabz on 27/04/19.
//

#include "StartingEvent.h"
#include "Utils/Condition.h"
#include "GameState.h"

StartingEvent::StartingEvent(Event *event, double baseProba) : event(event), baseProba(baseProba) {}

void StartingEvent::addCondition(Condition *condition) {
    conditions.emplace_back(condition);
}

void StartingEvent::addProba(string variable, double weight) {
    proba.insert(std::pair<string,double>(variable,weight));
}

bool StartingEvent::checkConditions() {
    bool cond = true;
    for (int i = 0; i < conditions.size(); ++i) {
        cond = cond && conditions[i]->checkCondition();
    }
    return cond;
}

double StartingEvent::getProba() {
    double cproba = baseProba;
    map<string,double>::iterator it;
    for (it = proba.begin(); it != proba.end() ; ++it) {
         cproba+=GameState::getGameVariable(it->first)*it->second;
    }
    return cproba;
}

Event *StartingEvent::getEvent() {
    return event;
}
