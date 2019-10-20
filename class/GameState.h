//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_GAMESTATE_H
#define ZELOTH_GAMESTATE_H

#include <map>
#include <string>

using std::map;
using std::string;

class GameState {
private:
    static bool exit;
    static map<string,double> gameVariables;
public:
    static bool isExit();
    static void setExit(bool exit);

    static void createGameVariable(const string& variable,double value);
    static void setGameVariable(const string& variable, double value);
    static double getGameVariable(const string& variable);
    static double incGameVariable(const string& variable, double value);



};


#endif //ZELOTH_GAMESTATE_H
