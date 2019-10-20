//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_ACTION_H
#define ZELOTH_ACTION_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class Consequence;

class Action {
private:
    string command;
    vector<Consequence *> consequences;
public:
    Action(const string &command);

    void addConsequence(Consequence *consequence);

    void doAction();

    const string &getCommand() const;
    void setCommand(const string &command);
};


#endif //ZELOTH_ACTION_H
