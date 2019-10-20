//
// Created by oxabz on 27/04/19.
//

#ifndef ZELOTH_PROCEDURALPICKING_H
#define ZELOTH_PROCEDURALPICKING_H

#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;

class StartingEvent;

class ProceduralPicking {
private:
    static map<string,vector<StartingEvent * >> startingEvents;
public:
    static void addGamePhase(string gamePhase);
    static void addStartingEvent(string gamePhase,StartingEvent * event);

    static void pickEvent();
};


#endif //ZELOTH_PROCEDURALPICKING_H
