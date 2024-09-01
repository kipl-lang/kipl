//
// Created by Kerem on 31/08/2024.
//

#include "trueBlock.h"
#include <stdlib.h>

#include "../global.h"

void createIf(unsigned int bracketsNumber) {
    If* newIf = (If*) malloc(sizeof(If));
    newIf->parentIf = currentIf;
    newIf->lastBracketsNumber = bracketsNumber;
    currentIf = newIf;
}

void freeIf(If* _if) {
    free(_if);
}