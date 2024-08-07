//
// Created by Kerem on 06/08/2024.
//

#include "expressionStack.h"

#include <stdlib.h>

ExpressionStack* createExpressionStack() {
    ExpressionStack* expressionStack = (ExpressionStack*) malloc(sizeof(ExpressionStack));
    expressionStack->capacity = 0;
    expressionStack->top = -1;
    expressionStack->elements = (ExpressionElement**) malloc(expressionStack->capacity*sizeof(ExpressionElement*));

    return expressionStack;
}

void pushExpressionStack(ExpressionStack* stack, ExpressionElement* element) {
    stack->elements = realloc(stack->elements, ++stack->capacity*sizeof(ExpressionStack*));
    stack->elements[++stack->top] = element;
}

ExpressionElement* popExpressionStack(ExpressionStack* stack) {
    if(stack->top == -1)
        return NULL;

    return stack->elements[stack->top--];
}