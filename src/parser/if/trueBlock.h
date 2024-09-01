//
// Created by Kerem on 31/08/2024.
//

#ifndef IF_H
#define IF_H


typedef struct _true_block {
    struct _true_block* parentTrueBlock;
    unsigned int lastBracketsNumber;
} TrueBlock;

void createTrueBlock(unsigned int bracketsNumber);

void freeTrueBlock(TrueBlock* trueBlock);

#endif //IF_H
