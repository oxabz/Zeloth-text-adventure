//
// Created by oxabz on 27/04/19.
//

#ifndef ZELOTH_STARTINGEVENT_H
#define ZELOTH_STARTINGEVENT_H

#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;

class Condition;
class Event;

class StartingEvent {
private:
    Event * event;
    vector<Condition *> conditions;
    map<string,double> proba;
    double baseProba;
public:
    StartingEvent(Event *event, double baseProba);

    void addCondition(Condition * condition);
    void addProba(string variable, double weight);

    bool checkConditions();
    double getProba();
    Event * getEvent();
};


#endif //ZELOTH_STARTINGEVENT_H
