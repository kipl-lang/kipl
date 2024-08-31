//
// Created by Kerem on 31/08/2024.
//

#ifndef IF_H
#define IF_H

#include "../../token/token.h"

typedef struct _if {
    struct _if* parentIf;
    unsigned int lastBracketsNumber;
} If;

void createIf(unsigned int bracketsNumber);

void freeIf(If* _if);

#endif //IF_H
