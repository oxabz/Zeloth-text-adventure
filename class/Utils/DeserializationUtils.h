//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_DESERIALIZATIONUTILS_H
#define ZELOTH_DESERIALIZATIONUTILS_H

#include <string>
#include <fstream>

using std::string;
using std::fstream;

#include "JsonAmalgamate/json/json.h"

class Event;
class Situation;
class Action;
class Consequence;
class Condition;
class CDisplayText;
class CChangeEvent;
class CChangeVariable;
class CIncVariable;
class CIf;
class CondAnd;
class CondOr;
class CondSuperior;
class CondSuperiorE;
class CondEquals;

class DeserializationUtils {
private:
    static const string VARIABLES_FILE_PATH;
    static Json::Value variablesJson;
    static const string EVENTS_FILE_PATH;
    static Json::Value eventsJson;

    static void deserializeVariable(const Json::Value &value);

    static Event* deserializeEvent(const Json::Value &value);

    static Situation* deserializeSituation(const Json::Value &value);

    static Action* deserializeAction(const Json::Value &value);

    static Consequence* deserializeConsequence(const Json::Value &value);
    static CDisplayText* deserializeCTextDisplay(const Json::Value &value);
    static CChangeEvent* deserializeCChangeEvent(const Json::Value &value);
    static CChangeVariable* deserializeCChangeVariable(const Json::Value &value);
    static CIncVariable* deserializeCIncVariable(const Json::Value &value);
    static CIf* deserializeCIf(const Json::Value &value);

    static Condition* deserializeCondition(const Json::Value &value);
    static Condition* deserializeConditionReduced(const string &cond);
    static CondAnd* deserializeCondAnd(const Json::Value &value);
    static CondOr* deserializeCondOr(const Json::Value &value);
    static CondSuperior* deserializeCondSuperior(const Json::Value &value);
    static CondSuperiorE* deserializeCondSuperiorE(const Json::Value &value);
    static CondEquals* deserializeCondEquals(const Json::Value &value);

    static Condition* conditionDeserialisationRecursive(string cond);

    static string parentessisParcours(string text, int &index);
public:
    static void loadVariables();

    static void loadEvents();
};


#endif //ZELOTH_DESERIALIZATIONUTILS_H
