//
// Created by Kerem on 04/08/2024.
//

#ifndef PARSEEXPRESSIONS_H
#define PARSEEXPRESSIONS_H

#include "data.h"
#include "expressionElement.h"
#include "expressionQueue.h"
#include "expressionStack.h"

typedef enum _associativity{
    ASSOCIATIVITY_LEFT,
    ASSOCIATIVITY_RIGHT
} Associativity;

Data* parseExpressions();

/*
 * @function: dataToExpressionElement
 * @description: Convert data to parse expression element
 * @arguments: Data* data
 * @return: ExpressionElement*
 */
ExpressionElement* dataToExpressionElement(Data* data);

/*
 * @function: expressionElementToData
 * @description: Convert expression element to data
 * @arguments: ExpressionElement* element
 * @return: Data*
 */
Data* expressionElementToData(ExpressionElement* element);

/*
 * @function: tokenToExpressionElement
 * @description: Convert token to parse expression
 * @arguments: nothing
 * @return: ExpressionElement*
 */
ExpressionElement* tokenToExpressionElement();

/*
 * @function: precedence
 * @description:
 * @arguments: get predence of operator
 * @return: int
 */
int precedence(ExpressionElement* element);

/*
 * @function: getAssociativity
 * @description: operator is left ASSOCIATIVITY_LEFT or ASSOCIATIVITY_LEFT
 * @arguments: ExpressionElement* element
 * @return: Associativity
 */
Associativity getAssociativity(ExpressionElement* element);

/*
 * @function: AddZeroExpressionElement
 * @description: if element is plus or minus and if previous element is NULL or '(' add zero element the queue
 * @arguments: ExpressionElement* element, ExpressionElement* prevElement, ExpressionQueue* queue
 * @return: void
 */
void
AddZeroExpressionElement(ExpressionElement* element, ExpressionElement* prevElement, ExpressionQueue* queue);

/*
 * @function: evaluatePostfix
 * @description: evaluate postfix expression and convert data
 * @arguments: ExpressionQueue* queue
 * @return: Data*
 */
Data* evaluatePostfix(ExpressionQueue* queue);

/*
 * @function: performArithmeticOperation
 * @description: perform the arithmetic operation
 * @arguments: ExpressionElement* o1, ExpressionElement* o2, ExpressionElement* operator
 * @return: ExpressionElement*
 */
ExpressionElement*
performArithmeticOperation(ExpressionElement* o1, ExpressionElement* o2, ExpressionElement* operator);

/*
 * @function: performComparisonOperation
 * @description: perform the comparison operation
 * @arguments: ExpressionElement* o1, ExpressionElement* o2, ExpressionElement* operator
 * @return: ExpressionElement*
 */
ExpressionElement*
performComparisonOperation(ExpressionElement* o1, ExpressionElement* o2, ExpressionElement* operator);

#endif //PARSEEXPRESSIONS_H
