//
// Created by oxabz on 22/04/19.
//

#include "GameState.h"

map<string,double > GameState::gameVariables;
bool GameState::exit = false;

bool GameState::isExit() {
    return exit;
}

void GameState::setExit(bool exit) {
    GameState::exit = exit;
}

void GameState::createGameVariable(const string& variable, double value) {
    gameVariables.insert(std::pair<string,double>(variable,value));
}

void GameState::setGameVariable(const string& variable, double value) {
    gameVariables[variable] = value;
}

double GameState::getGameVariable(const string& variable) {
    return gameVariables[variable];
}

double GameState::incGameVariable(const string& variable, double value) {
    return gameVariables[variable]+=value;
}

