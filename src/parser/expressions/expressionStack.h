//
// Created by Kerem on 06/08/2024.
//

#ifndef EXPRESSIONSTACK_H
#define EXPRESSIONSTACK_H

#include "expressionElement.h"

typedef struct _expression_stack {
    int top;
    unsigned int capacity;
    ExpressionElement** elements;
} ExpressionStack;

ExpressionStack* createExpressionStack();

void pushExpressionStack(ExpressionStack* stack, ExpressionElement* element) ;

ExpressionElement* popExpressionStack(ExpressionStack* stack);

ExpressionElement* peekExpressionStack(ExpressionStack* stack);

void freeExpressionStack();

#endif //EXPRESSIONSTACK_H
