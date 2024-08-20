//
// Created by Kerem on 19/08/2024.
//

#ifndef FOR_H
#define FOR_H

#include "../../token/token.h"

typedef struct _for {
    Token* forToken;
    struct _for* parentFor;
    unsigned int lastBracketsNumber;
} For;

void createFor(Token* token, unsigned int bracketsNumber);

void freeFor(For* _for);

#endif //FOR_H
