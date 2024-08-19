//
// Created by Kerem on 19/08/2024.
//

#include "for.h"

#include <stdlib.h>

For* createFor(Token* token, unsigned int bracketsNumber) {
    For* newFor = (For*) malloc(sizeof(For));
    newFor->forToken = token;
    newFor->nextFor = NULL;
    newFor->lastBracketsNumber = bracketsNumber;

    return newFor;
}
