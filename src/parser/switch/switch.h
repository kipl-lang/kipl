//
// Created by Kerem on 04/09/2024.
//

#ifndef SWITCH_H
#define SWITCH_H

#include "../expressions/data.h"

typedef struct _switch {
    Data* data;
    struct _switch* parentSwitch;
    unsigned int lastBracketsNumber;
} Switch;

void createSwitch(Data* data, unsigned int bracketsNumber);

void freeSwitch(Switch* _switch);

#endif //SWITCH_H
