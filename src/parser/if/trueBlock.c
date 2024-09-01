//
// Created by Kerem on 31/08/2024.
//

#include "trueBlock.h"
#include <stdlib.h>

#include "../global.h"

void createTrueBlock(unsigned int bracketsNumber) {
    TrueBlock* newTrueBlock = (TrueBlock*) malloc(sizeof(TrueBlock));
    newTrueBlock->parentTrueBlock = currentTrueBlock;
    newTrueBlock->lastBracketsNumber = bracketsNumber;
    currentTrueBlock = newTrueBlock;
}

void freeTrueBlock(TrueBlock* trueBlock) {
    free(trueBlock);
}