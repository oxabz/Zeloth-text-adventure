#include <iostream>
#include "class/Event.h"
#include "class/Situation.h"
#include "class/Action.h"
#include "class/Consequences/CDisplayText.h"
#include "class/Consequences/CChangeEvent.h"
#include "class/Consequences/CIf.h"
#include "class/Utils/Conditions/CondSuperior.h"
#include "class/GameState.h"
#include "class/Consequences/CChangeVariable.h"
#include "class/Consequences/CIncVariable.h"
#include "class/Utils/DeserializationUtils.h"
#include "class/Utils/DisplayUtils.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    

    DeserializationUtils::loadVariables();
    DeserializationUtils::loadEvents();

    DisplayUtils::initDisplay();
    
    Event::getEventFromID(0)->playEvent();

    return 0;
}