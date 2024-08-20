//
// Created by Kerem on 19/08/2024.
//

#include "for.h"

#include <stdlib.h>

#include "../global.h"

void createFor(Token* token, unsigned int bracketsNumber) {
    For* newFor = (For*) malloc(sizeof(For));
    newFor->forToken = token;
    newFor->parentFor = NULL;
    newFor->lastBracketsNumber = bracketsNumber;

    newFor->parentFor = currentFor;
    currentFor = newFor;
}

void freeFor(For* _for) {
    free(_for);
}