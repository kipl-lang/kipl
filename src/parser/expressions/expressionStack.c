//
// Created by Kerem on 06/08/2024.
//

#include "expressionStack.h"

#include <stdlib.h>

ExpressionStack* createExpressionStack() {
    ExpressionStack* expressionStack = (ExpressionStack*) malloc(sizeof(ExpressionStack));
    expressionStack->top = -1;
    expressionStack->elements = NULL;

    return expressionStack;
}
