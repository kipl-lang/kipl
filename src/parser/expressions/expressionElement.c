//
// Created by Kerem on 06/08/2024.
//

#include "expressionElement.h"

#include <stdlib.h>

ExpressionElement* createEXpressionElement(ExpressionElementType type, char* value) {
    ExpressionElement* exprElement = (ExpressionElement*) malloc(sizeof(ExpressionElement)); // New Element
    exprElement->type = type;
    exprElement->value = value;

    return exprElement;
}

void freeExpressionElement(ExpressionElement* element) {
    free(element);
}

