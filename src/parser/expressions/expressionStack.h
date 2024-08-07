//
// Created by Kerem on 06/08/2024.
//

#ifndef EXPRESSIONSTACK_H
#define EXPRESSIONSTACK_H

#include "expressionElement.h"

typedef struct _expression_stack {
    unsigned int top;
    unsigned int capacity;
    ExpressionElement** elements;
} ExpressionStack;

ExpressionStack* createExpressionStack();

void pushExpressionStack(ExpressionElement* element);

void popExpressionStack();

void freeExpressionStack();

#endif //EXPRESSIONSTACK_H
