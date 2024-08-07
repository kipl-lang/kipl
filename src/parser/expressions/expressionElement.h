//
// Created by Kerem on 06/08/2024.
//

#ifndef EXPRESSIONELEMENT_H
#define EXPRESSIONELEMENT_H

typedef enum _expression_element_type {
    ELEMENT_TYPE_NUMBER,
    ELEMENT_TYPE_STRING,
    ELEMENT_TYPE_BOOL,
    ELEMENT_TYPE_OPERATOR_PLUS,
    ELEMENT_TYPE_OPERATOR_MINUS,
    ELEMENT_TYPE_OPERATOR_MULTIPLY,
    ELEMENT_TYPE_OPERATOR_DIVIDE,
    ELEMENT_TYPE_OPERATOR_MODULE,
    ELEMENT_TYPE_OPERATOR_POWER,
    ELEMENT_TYPE_BRACKET_R_L,           // bracket round left
    ELEMENT_TYPE_BRACKET_R_R,           // beacket round right
} ExpressionElementType;

typedef struct _expression_element {
    ExpressionElementType type;
    char* value;
    struct _expression_element* next;
} ExpressionElement;

ExpressionElement* createExpressionElement(ExpressionElementType type, char* value);

void freeExpressionElement(ExpressionElement* element);

#endif //EXPRESSIONELEMENT_H
