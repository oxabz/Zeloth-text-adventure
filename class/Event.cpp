//
// Created by oxabz on 22/04/19.
//

#include "Event.h"
#include "Situation.h"
#include "Action.h"
#include "Utils/DisplayUtils.h"
#include "GameState.h"
#include "Consequences/CExitMesage.h"
#include "Consequences/CHelp.h"

map<int,Event *> Event::allEvents;

Event::Event(int id,Situation *situation) : situation(situation),id(id) {
    allEvents.insert(std::pair<int,Event *>(id,this));
    Action * exitAction = new Action ("exit");
    exitAction->addConsequence(new CExitMesage);
    Action * helpAction = new Action ("help");
    helpAction->addConsequence(new CHelp(this));
    this->addAction(exitAction);
    this->addAction(helpAction);
}

void Event::addAction(Action *action) {
    actions.insert(std::pair<string,Action*>(action->getCommand(),action));
}

Event * Event::getEventFromID(int id) {
    return allEvents[id];
}

void Event::playEvent() {
    do{
        DisplayUtils::DisplayText(situation->getSituation());

        playerTurn();
    }while(!GameState::isExit());
}

void Event::playerTurn() {
    string input = DisplayUtils::GetPlayerInput();

    map<string,Action * >::iterator it = actions.find(input);
    if(it != actions.end()){
        it->second->doAction();
    }else{
        DisplayUtils::DisplayText("Unknown Action");
    }
}

vector<string> Event::getCommands() {
    vector<string> commands;
    for (map<string,Action *>::iterator it = actions.begin(); it != actions.end() ; ++it) {
        commands.emplace_back(it->first);
    }
    return commands;
}

