//
// Created by oxabz on 22/04/19.
//

#include "DeserializationUtils.h"
#include "../GameState.h"
#include "../Event.h"
#include "../Situation.h"
#include "../Action.h"
#include "../Consequences/CDisplayText.h"
#include "../Consequences/CChangeEvent.h"
#include "../Consequences/CChangeVariable.h"
#include "../Consequences/CIncVariable.h"
#include "../Consequences/CIf.h"
#include "../Consequences/CExitMesage.h"
#include "Conditions/CondAnd.h"
#include "Conditions/CondOr.h"
#include "Conditions/CondSuperior.h"
#include "Conditions/CondSuperiorE.h"
#include "Conditions/CondEquals.h"

#include <iostream>

const string DeserializationUtils::VARIABLES_FILE_PATH("Resources/variables.json");
Json::Value DeserializationUtils::variablesJson;
const string DeserializationUtils::EVENTS_FILE_PATH("Resources/events.json");
Json::Value DeserializationUtils::eventsJson;

void DeserializationUtils::loadVariables() {
    std::fstream f(VARIABLES_FILE_PATH);
    if(f.is_open()){
        f>>variablesJson;
        for (int i = 0; i < variablesJson.size(); ++i) {
            deserializeVariable(variablesJson[i]);
        }
    } else{
        std::cout<<"fichier non ouvert";
    }
}

void DeserializationUtils::deserializeVariable(const Json::Value &value) {
    GameState::createGameVariable(value["name"].asString(),value["value"].asDouble());
}

void DeserializationUtils::loadEvents() {
    std::fstream f(EVENTS_FILE_PATH);
    if(f.is_open()){
        f>>eventsJson;
        for (int i = 0; i < eventsJson.size(); ++i) {
            deserializeEvent(eventsJson[i]);
        }
    } else{
        std::cout<<"fichier non ouvert";
    }
}

Event* DeserializationUtils::deserializeEvent(const Json::Value &value) {
    Event * event = new Event(value["id"].asInt(),deserializeSituation(value["situation"]));
    for (int i = 0; i < value["actions"].size(); ++i) {
        event->addAction(deserializeAction(value["actions"][i]));
    }
    return event;
}

Situation* DeserializationUtils::deserializeSituation(const Json::Value &value) {
    return new Situation(value["text"].asString());
}

Action *DeserializationUtils::deserializeAction(const Json::Value &value) {
    Action * action = new Action(value["command"].asString());
    for (int i = 0; i < value["consequences"].size(); ++i) {
        action->addConsequence(deserializeConsequence(value["consequences"][i]));
    }
    return action;
}

Consequence *DeserializationUtils::deserializeConsequence(const Json::Value &value) {
    string type = value["type"].asString();
    if(type=="DisplayText"){
        return deserializeCTextDisplay(value);
    } else if(type=="ChangeEvent"){
        return deserializeCChangeEvent(value);
    } else if(type=="ChangeVariable"){
        return deserializeCChangeVariable(value);
    } else if(type=="IncVariable"){
        return deserializeCIncVariable(value);
    } else if(type=="If"){
        return deserializeCIf(value);
    } else if(type=="Exit"){
        return new CExitMesage();
    } else{
        return nullptr;
    }
}

CDisplayText *DeserializationUtils::deserializeCTextDisplay(const Json::Value &value) {
    return new CDisplayText(value["text"].asString());
}

CChangeEvent *DeserializationUtils::deserializeCChangeEvent(const Json::Value &value) {
    return new CChangeEvent(value["id"].asInt());
}

CChangeVariable *DeserializationUtils::deserializeCChangeVariable(const Json::Value &value) {
    return new CChangeVariable(value["variable"].asString(),value["value"].asDouble());
}

CIncVariable *DeserializationUtils::deserializeCIncVariable(const Json::Value &value) {
    return new CIncVariable(value["variable"].asString(),value["value"].asDouble());
}

CIf *DeserializationUtils::deserializeCIf(const Json::Value &value) {
    Condition* condition;
    if(value["cond"].isString()){
        condition = deserializeConditionReduced(value["cond"].asString());
    } else{
        condition=deserializeCondition(value["cond"]);
    }
    CIf* cIf = new CIf(condition);
    cout<<value<<endl;
    for (int i = 0; i < value["consequences"].size(); ++i) {
        cIf->addConsequence(deserializeConsequence(value["consequence"][i]));
    }
    return cIf;
}

Condition *DeserializationUtils::deserializeCondition(const Json::Value &value) {
    string type = value["type"].asString();
    if(type=="And"){
        return deserializeCondAnd(value);
    } else if(type=="Or"){
        return deserializeCondOr(value);
    } else if(type==">"){
        return deserializeCondSuperior(value);
    } else if(type==">="){
        return deserializeCondSuperiorE(value);
    } else if(type=="="){
        return deserializeCondEquals(value);
    } else{
        return nullptr;
    }
}

CondAnd *DeserializationUtils::deserializeCondAnd(const Json::Value &value) {
    return new CondAnd(deserializeCondition(value["cond1"]),deserializeCondition(value["cond2"]));
}

CondOr *DeserializationUtils::deserializeCondOr(const Json::Value &value) {
    return new CondOr(deserializeCondition(value["cond1"]),deserializeCondition(value["cond2"]));
}

CondSuperior *DeserializationUtils::deserializeCondSuperior(const Json::Value &value) {
    return new CondSuperior(value["varSup"].asString(),value["varInf"].asString());
}

CondSuperiorE *DeserializationUtils::deserializeCondSuperiorE(const Json::Value &value) {
    return new CondSuperiorE(value["varSup"].asString(),value["varInf"].asString());
}

CondEquals *DeserializationUtils::deserializeCondEquals(const Json::Value &value) {
    return new CondEquals(value["var1"].asString(),value["var2"].asString());
}

Condition *DeserializationUtils::deserializeConditionReduced(const string &cond) {
    return conditionDeserialisationRecursive(cond);
}

Condition* DeserializationUtils::conditionDeserialisationRecursive(string cond) {
    string firstElement;
    char inbeetwin = ' ';
    string secondElement;
    Condition* _condition = nullptr;

    int i = 0;
    while(i<cond.size()&&inbeetwin == ' '){
        if(cond[i]=='('){
            firstElement = parentessisParcours(cond, i);
        }else if(cond[i]=='|'||cond[i]=='&') {
            inbeetwin = cond[i];
        } else{
            firstElement+=cond[i];
        }
        i++;
    }
    if(inbeetwin == '|'){
        _condition = new CondOr(conditionDeserialisationRecursive(firstElement),conditionDeserialisationRecursive(string(cond.begin()+i,cond.end())));
    }
    else if(inbeetwin == '&'){
        _condition = new CondAnd(conditionDeserialisationRecursive(firstElement),conditionDeserialisationRecursive(string(cond.begin()+i,cond.end())));
    } else{
        int i = 0;
        firstElement.clear();
        while(i<cond.size()&&inbeetwin == ' '){
            if(cond[i]=='('){
                firstElement = parentessisParcours(cond, i);
            }else if(cond[i]=='<'||cond[i]=='>'||cond[i]=='=') {
                inbeetwin = cond[i];
            } else{
                firstElement+=cond[i];
            }
            i++;
        }
        if(inbeetwin == '<'){
            _condition = new CondSuperior(string(cond.begin()+i,cond.end()),firstElement);
        } else if(inbeetwin == '>'){
            _condition = new CondSuperior(firstElement,string(cond.begin()+i,cond.end()));
        } else if (inbeetwin == '='){
            _condition = new CondEquals(firstElement,string(cond.begin()+i,cond.end()));
        }
    }

    return _condition;
}

string DeserializationUtils::parentessisParcours(string text, int &index) {
    string temp;
    int count = 1;
    index++;
    while(index<text.size()&&count<=0){
        temp+=text[index];
        if(text[index] == '('){
            count++;
        }else if(text[index] == ')'){
            count--;
            if(count==0){
                temp.pop_back();
            }
        }
        index++;
    }

    return temp;
}
