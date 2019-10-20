//
// Created by oxabz on 27/04/19.
//

#include "ProceduralPicking.h"
#include "../GameState.h"
#include "../StartingEvent.h"


map<string,vector<StartingEvent * >> ProceduralPicking::startingEvents;

void ProceduralPicking::addGamePhase(string gamePhase) {
    startingEvents.insert(std::pair<string,vector<StartingEvent *>>(gamePhase,vector<StartingEvent *>()));
}

void ProceduralPicking::addStartingEvent(string gamePhase, StartingEvent * event) {
    startingEvents[gamePhase].emplace_back(event);
}

void ProceduralPicking::pickEvent() {
    map<double,StartingEvent *> startingSet;
    double range = 0;
    for (int i = 0; i < startingEvents["temp"].size(); ++i) {
        if(startingEvents["temp"][i]->checkConditions()){
            range+=startingEvents["temp"][i]->getProba();
            startingSet.insert(std::pair<double ,StartingEvent *>(range,startingEvents["temp"][i]));
        }
    }
}
