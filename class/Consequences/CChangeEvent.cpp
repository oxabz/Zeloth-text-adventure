//
// Created by oxabz on 22/04/19.
//

#include "CChangeEvent.h"
#include "../Event.h"

CChangeEvent::CChangeEvent(int id) : id(id) {}

void CChangeEvent::doConsequence() {
    Event::getEventFromID(id)->playEvent();
}
