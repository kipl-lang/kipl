//
// Created by Kerem on 04/08/2024.
//

#ifndef PARSEEXPRESSIONS_H
#define PARSEEXPRESSIONS_H

#include "data.h"
#include "expressionElement.h"

typedef enum _associativity{
    ASSOCIATIVITY_LEFT,
    ASSOCIATIVITY_RIGHT
} Associativity;

Data* parseExpressions();

/*
 * @function: dataToExpressionElement
 * @description: Convert data to parse expression
 * @arguments: Data* data
 * @return: ExpressionElement*
 */
ExpressionElement* dataToExpressionElement(Data* data);

/*
 * @function: tokenToExpressionElement
 * @description: Convert token to parse expression
 * @arguments: nothing
 * @return: ExpressionElement*
 */
ExpressionElement* tokenToExpressionElement();

int precedence(ExpressionElement* element);

Associativity getAssociativity(ExpressionElement* element);

#endif //PARSEEXPRESSIONS_H
