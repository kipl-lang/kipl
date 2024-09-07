//
// Created by Kerem on 04/09/2024.
//

#include "switch.h"

#include <stdlib.h>

#include "../global.h"

void createSwitch(Data* data, unsigned int bracketsNumber) {
    Switch* newSwitch = (Switch*) malloc(sizeof(Switch));
    newSwitch->data = data;
    newSwitch->lastBracketsNumber = bracketsNumber;
    newSwitch->parentSwitch = currentSwitch;
    newSwitch->caseStatus = false;
    currentSwitch = newSwitch;
}



void freeSwitch(Switch* _switch) {
    free(_switch->data);
    free(_switch);
}