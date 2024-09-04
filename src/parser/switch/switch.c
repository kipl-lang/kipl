//
// Created by Kerem on 04/09/2024.
//

#include "switch.h"

#include <stdlib.h>

#include "../global.h"

void createSwitch(unsigned int bracketsNumber) {
    Switch* newSwitch = (Switch*) malloc(sizeof(Switch));
    newSwitch->lastBracketsNumber = bracketsNumber;
    newSwitch->parentSwitch = currentSwitch;
    currentSwitch = newSwitch;
}



void freeSwitch(Switch* _switch) {
    free(_switch);
}