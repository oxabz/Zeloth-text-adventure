//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_EVENT_H
#define ZELOTH_EVENT_H

#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;

class Action;
class Situation;

class Event {
private:
    static map<int,Event*> allEvents;
public:
    static Event * getEventFromID(int id);

private:
    int id;
    Situation *situation;
    map<string,Action *> actions;

    void playerTurn();
public:
    Event(int id,Situation *situation);

    void addAction(Action *action);
    vector<string> getCommands();

    void playEvent();
};


#endif //ZELOTH_EVENT_H
