//
// Created by Kerem on 04/08/2024.
//

#ifndef PARSEEXPRESSIONS_H
#define PARSEEXPRESSIONS_H

#include "data.h"
#include "expressionElement.h"

Data* parseExpressions();

ExpressionElement* dataToExpressionElement(Data* data);

int precedence(ExpressionElement* element);

#endif //PARSEEXPRESSIONS_H
