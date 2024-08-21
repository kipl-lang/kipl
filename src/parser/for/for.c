//
// Created by Kerem on 19/08/2024.
//

#include <stdlib.h>
#include "for.h"
#include "../global.h"

void createFor(Token* token, unsigned int bracketsNumber) {
    For* newFor = (For*) malloc(sizeof(For));
    newFor->forToken = token;
    newFor->parentFor = currentFor;
    newFor->lastBracketsNumber = bracketsNumber;
    currentFor = newFor;
}

void freeFor(For* _for) {
    free(_for);
}