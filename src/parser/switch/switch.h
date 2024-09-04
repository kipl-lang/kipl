//
// Created by Kerem on 04/09/2024.
//

#ifndef SWITCH_H
#define SWITCH_H

typedef struct _switch {
    struct _switch* parentSwitch;
    unsigned int lastBracketsNumber;
} Switch;

void createSwitch(unsigned int bracketsNumber);

void freeSwitch(Switch* _switch);

#endif //SWITCH_H
