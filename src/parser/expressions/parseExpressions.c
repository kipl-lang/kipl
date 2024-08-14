//
// Created by Kerem on 04/08/2024.
//

#include "parseExpressions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expressionQueue.h"
#include "expressionStack.h"
#include "../global.h"
#include "../../token/token.h"
#include "../error/error.h"
#include "../helpers/typeConversion/toBool.h"
#include "../helpers/typeConversion/toString.h"

Data* parseExpressions() {
    if(currentToken->type == TOKEN_EOF)
        return NULL;

    ExpressionStack* stackOperator = createExpressionStack();
    ExpressionQueue* queueOutput = createExpressionQueue();
    unsigned int openBracket = 0; // Open bracket number

    while(currentToken->type != TOKEN_EOF) {
        if(currentToken->type == TOKEN_IDENTIFIER) {
            Data* data = getDataFromVariable(currentToken->value);
            if(data != NULL) {
                ExpressionElement* element = dataToExpressionElement(data);
                enqueueExpression(queueOutput, element);
            } else { // variable is not defined
                char errMsg[256];
                sprintf(errMsg, "%s undefined", currentToken->value);
                showError(ERROR_RUNTIME, errMsg);
            }
        } else {
            ExpressionElement* element = tokenToExpressionElement();
            if(element == NULL) // element is not a expression element
                break;

            if(element->type == ELEMENT_TYPE_NUMBER || element->type == ELEMENT_TYPE_BOOL ||
                element->type == ELEMENT_TYPE_STRING) {
                enqueueExpression(queueOutput, element);
            } else if(element->type == ELEMENT_TYPE_BRACKET_R_L) {
                pushExpressionStack(stackOperator, element);
                openBracket++;
            } else if(element->type == ELEMENT_TYPE_BRACKET_R_R) {
                freeExpressionElement(element);

                while(peekExpressionStack(stackOperator) != NULL &&
                    peekExpressionStack(stackOperator)->type != ELEMENT_TYPE_BRACKET_R_L
                    )
                    enqueueExpression(queueOutput, popExpressionStack(stackOperator));

                if(peekExpressionStack(stackOperator) != NULL &&
                    peekExpressionStack(stackOperator)->type == ELEMENT_TYPE_BRACKET_R_L
                    ) // pop '('
                    freeExpressionElement(popExpressionStack(stackOperator));

                openBracket--;
            } else { // operator
                if(peekExpressionStack(stackOperator) == NULL)
                    pushExpressionStack(stackOperator, element);
                else {
                    if(getAssociativity(element) == ASSOCIATIVITY_LEFT) {
                        while(peekExpressionStack(stackOperator) != NULL &&
                            precedence(peekExpressionStack(stackOperator)) >= precedence(element)
                            ) {
                            enqueueExpression(queueOutput, popExpressionStack(stackOperator));
                        }
                        pushExpressionStack(stackOperator, element);
                    } else if(getAssociativity(element) == ASSOCIATIVITY_RIGHT) {
                        while(precedence(peekExpressionStack(stackOperator)) > precedence(element)) {
                            enqueueExpression(queueOutput, popExpressionStack(stackOperator));
                        }
                        pushExpressionStack(stackOperator, element);
                    }
                }
            }
        }
        currentToken = currentToken->next;
    }

    if(currentToken->type == TOKEN_ERROR)
        showError(ERROR_SYNTAX, currentToken->value);

    if(openBracket != 0)
        showError(ERROR_SYNTAX, "Brackets are not balanced");

    // After processing all tokens, pop any remaining operators from the stack and enqueue them
    while (peekExpressionStack(stackOperator) != NULL)
        enqueueExpression(queueOutput, popExpressionStack(stackOperator));

    Data* data = evaluatePostfix(queueOutput);

    freeExpressionStack(stackOperator); // free the stack
    freeExpressionQueue(queueOutput);   // free the queue

    return data;
}

ExpressionElement* dataToExpressionElement(Data* data) {
    ExpressionElementType type;
    char* value = strdup(data->value);

    switch(data->dataType) {
        case TYPE_I8:
        case TYPE_I16:
        case TYPE_I32:
        case TYPE_I64:
        case TYPE_I128:
        case TYPE_U8:
        case TYPE_U16:
        case TYPE_U32:
        case TYPE_U64:
        case TYPE_U128:
        case TYPE_F32:
        case TYPE_F64:
            type = ELEMENT_TYPE_NUMBER;
            break;
        case TYPE_BOOL:
            type = ELEMENT_TYPE_BOOL;
            break;
        case TYPE_STRING:
            type = ELEMENT_TYPE_STRING;
            break;
        default:
            break;
    }

    freeData(data);
    return createExpressionElement(type, value);
}

Data* expressionElementToData(ExpressionElement* element) {
    DataType type;
    char* value = strdup(element->value);

    switch(element->type) {
        case ELEMENT_TYPE_NUMBER:
            if(strchr(element->value, '.') != NULL)
                type = TYPE_F64;
            else if(strchr(element->value, '-') != NULL)
                type = TYPE_I128;
            else
                type = TYPE_U128;
        case ELEMENT_TYPE_BOOL:
            type = TYPE_BOOL;
            break;
        case ELEMENT_TYPE_STRING:
            type = TYPE_STRING;
            break;
        default:
            type = TYPE_VOID;
            break;
    }

    freeExpressionElement(element);
    return createData(type, value);
}

ExpressionElement* tokenToExpressionElement() {
    ExpressionElementType type;

    switch(currentToken->type) {
        case TOKEN_NUMBER_LITERAL:
            type = ELEMENT_TYPE_NUMBER;
            break;
        case TOKEN_BOOL_TRUE:
        case TOKEN_BOOL_FALSE:
            type = ELEMENT_TYPE_BOOL;
            break;
        case TOKEN_STRING_LITERAL:
            type = ELEMENT_TYPE_STRING;
            break;
        case TOKEN_PLUS:
            type = ELEMENT_TYPE_OPERATOR_PLUS;
            break;
        case TOKEN_MINUS:
            type = ELEMENT_TYPE_OPERATOR_MINUS;
            break;
        case TOKEN_MULTPLY:
            type = ELEMENT_TYPE_OPERATOR_MULTIPLY;
            break;
        case TOKEN_DIVIDE:
            type = ELEMENT_TYPE_OPERATOR_DIVIDE;
            break;
        case TOKEN_MODULUS:
            type = ELEMENT_TYPE_OPERATOR_MODULE;
            break;
        case TOKEN_POWER:
            type = ELEMENT_TYPE_OPERATOR_POWER;
            break;
        case TOKEN_LESS:
            type = ELEMENT_TYPE_OPERATOR_LESS;
            break;
        case TOKEN_GREAT:
            type = ELEMENT_TYPE_OPERATOR_GREAT;
            break;
        case TOKEN_LESS_EQUAL:
            type = ELEMENT_TYPE_OPERATOR_LESS_EQUAL;
            break;
        case TOKEN_GREAT_EQUAL:
            type = ELEMENT_TYPE_OPERATOR_GREAT_EQUAL;
            break;
        case TOKEN_EQUAL_EQUAL:
            type = ELEMENT_TYPE_OPERATOR_EQUAL_EQUAL;
            break;
        case TOKEN_BANG_EQUAL:
            type = ELEMENT_TYPE_OPERATOR_BANG_EQUAL;
            break;
        case TOKEN_AND:
            type = ELEMENT_TYPE_OPERATOR_AND;
            break;
        case TOKEN_OR:
            type = ELEMENT_TYPE_OPERATOR_OR;
            break;
        case TOKEN_BANG:
            type = ELEMENT_TYPE_OPERATOR_BANG;
            break;
        case TOKEN_BRACKET_ROUND_LEFT:
            type = ELEMENT_TYPE_BRACKET_R_L;
            break;
        case TOKEN_BRACKET_ROUND_RIGHT:
            type = ELEMENT_TYPE_BRACKET_R_R;
            break;
        default:
            return NULL; // if token is not a expression element
    }

    char* value = strdup(currentToken->value);

    return createExpressionElement(type, value);
}

int precedence(ExpressionElement* element) {
    switch(element->type) {
        case ELEMENT_TYPE_OPERATOR_BANG:
            return 6;
        case ELEMENT_TYPE_OPERATOR_POWER:
            return 5;
        case ELEMENT_TYPE_OPERATOR_MULTIPLY:
        case ELEMENT_TYPE_OPERATOR_DIVIDE:
        case ELEMENT_TYPE_OPERATOR_MODULE:
            return 4;
        case ELEMENT_TYPE_OPERATOR_PLUS:
        case ELEMENT_TYPE_OPERATOR_MINUS:
            return 3;
        case ELEMENT_TYPE_OPERATOR_LESS:
        case ELEMENT_TYPE_OPERATOR_GREAT:
        case ELEMENT_TYPE_OPERATOR_LESS_EQUAL:
        case ELEMENT_TYPE_OPERATOR_GREAT_EQUAL:
        case ELEMENT_TYPE_OPERATOR_EQUAL_EQUAL:
        case ELEMENT_TYPE_OPERATOR_BANG_EQUAL:
            return 2;
        case ELEMENT_TYPE_OPERATOR_AND:
        case ELEMENT_TYPE_OPERATOR_OR:
            return 1;
        default:
            return 0;
    }
}

Associativity getAssociativity(ExpressionElement* element) {
    switch(element->type) {
        case ELEMENT_TYPE_OPERATOR_BANG:
        case ELEMENT_TYPE_OPERATOR_POWER:
            return ASSOCIATIVITY_RIGHT;
        default:
            return ASSOCIATIVITY_LEFT;
    }
}

Data* evaluatePostfix(ExpressionQueue* queue) {

    ExpressionStack* evaluateStack = createExpressionStack();

    for(int i=queue->front; i<=queue->rear; i++) {
        ExpressionElement* element = queue->elements[i];

        if(element->type == ELEMENT_TYPE_NUMBER ||
            element->type == ELEMENT_TYPE_BOOL  ||
            element->type == ELEMENT_TYPE_STRING
            ) {
            pushExpressionStack(evaluateStack, element);
        } else if(element->type == ELEMENT_TYPE_OPERATOR_BANG) {
            ExpressionElement* lastElement = popExpressionStack(evaluateStack);

            if(lastElement != NULL && lastElement->type == ELEMENT_TYPE_BOOL) { // !
                char* value = boolToString(!stringToBool(lastElement->value));
                freeExpressionElement(lastElement);
                freeExpressionElement(element);
                pushExpressionStack(evaluateStack, createExpressionElement(ELEMENT_TYPE_BOOL, value));
            } else {
                showError(ERROR_SYNTAX, "'!' operator can only be applied to boolean expressions");
            }
        } else if(element->type == ELEMENT_TYPE_OPERATOR_AND) { // &&
            ExpressionElement* lastElement1 = popExpressionStack(evaluateStack);
            ExpressionElement* lastElement2 = popExpressionStack(evaluateStack);

            if(lastElement1 != NULL && lastElement2 != NULL &&
                lastElement1->type == ELEMENT_TYPE_BOOL && lastElement2->type == ELEMENT_TYPE_BOOL
                ) {
                char* value =
                    boolToString(stringToBool(lastElement1->value) && stringToBool(lastElement2->value));
                freeExpressionElement(lastElement1);
                freeExpressionElement(lastElement2);
                freeExpressionElement(element);
                pushExpressionStack(evaluateStack, createExpressionElement(ELEMENT_TYPE_BOOL, value));
            } else {
                showError(ERROR_SYNTAX, "'&&' operator can only be applied to boolean expressions");
            }
        } else if(element->type == ELEMENT_TYPE_OPERATOR_OR) { // ||
            ExpressionElement* lastElement1 = popExpressionStack(evaluateStack);
            ExpressionElement* lastElement2 = popExpressionStack(evaluateStack);

            if(lastElement1 != NULL && lastElement2 != NULL &&
                lastElement1->type == ELEMENT_TYPE_BOOL && lastElement2->type == ELEMENT_TYPE_BOOL
                ) {
                char* value =
                    boolToString(stringToBool(lastElement1->value) || stringToBool(lastElement2->value));
                freeExpressionElement(lastElement1);
                freeExpressionElement(lastElement2);
                freeExpressionElement(element);
                pushExpressionStack(evaluateStack, createExpressionElement(ELEMENT_TYPE_BOOL, value));
            } else {
                showError(ERROR_SYNTAX, "'||' operator can only be applied to boolean expressions");
            }
        } else if(element->type == ELEMENT_TYPE_OPERATOR_PLUS) { // +
            ExpressionElement* lastElement1 = popExpressionStack(evaluateStack);
            ExpressionElement* lastElement2 = popExpressionStack(evaluateStack);

            if(lastElement1 != NULL && lastElement2 != NULL &&
                lastElement1->type == ELEMENT_TYPE_STRING && lastElement2->type == ELEMENT_TYPE_STRING
                ) {
                char value[strlen(lastElement1->value) + strlen(lastElement2->value) + 1];
                sprintf(value, "%s%s", lastElement2->value, lastElement1->value);
                freeExpressionElement(lastElement1);
                freeExpressionElement(lastElement2);
                freeExpressionElement(element);
                pushExpressionStack(evaluateStack,
                    createExpressionElement(ELEMENT_TYPE_STRING, strdup(value)));

            } else if(lastElement1 != NULL && lastElement2 != NULL &&
                lastElement1->type == ELEMENT_TYPE_NUMBER && lastElement2->type == ELEMENT_TYPE_NUMBER
                ) {
                ExpressionElement* newElement =
                    performArithmeticOperation(lastElement2, lastElement1, element);
                pushExpressionStack(evaluateStack, newElement);

            } else if(lastElement1 != NULL && lastElement1->type == ELEMENT_TYPE_NUMBER) {
                char* value = strdup(lastElement1->value);

                freeExpressionElement(lastElement1);
                freeExpressionElement(element);
                pushExpressionStack(evaluateStack,
                    createExpressionElement(ELEMENT_TYPE_NUMBER, value));
            }  else {
                showError(ERROR_SYNTAX, "'+' operator was used incorrectly");
            }

        } else if(element->type == ELEMENT_TYPE_OPERATOR_MINUS) {
            ExpressionElement* lastElement1 = popExpressionStack(evaluateStack);
            ExpressionElement* lastElement2 = popExpressionStack(evaluateStack);

            if(lastElement1 != NULL && lastElement2 != NULL &&
                lastElement1->type == ELEMENT_TYPE_NUMBER && lastElement2->type == ELEMENT_TYPE_NUMBER
                ) {
                ExpressionElement* newElement =
                    performArithmeticOperation(lastElement2, lastElement1, element);
                pushExpressionStack(evaluateStack, newElement);

            } else if(lastElement1 != NULL && lastElement1->type == ELEMENT_TYPE_NUMBER) {
                char* value =  doubleToString(-1 * atof(lastElement1->value));

                freeExpressionElement(lastElement1);
                freeExpressionElement(element);
                pushExpressionStack(evaluateStack,
                    createExpressionElement(ELEMENT_TYPE_NUMBER, value));
            } else {
                showError(ERROR_SYNTAX, "'-' operator was used incorrectly");
            }
        } else if(element->type == ELEMENT_TYPE_OPERATOR_MULTIPLY ||
            element->type == ELEMENT_TYPE_OPERATOR_DIVIDE         ||
            element->type == ELEMENT_TYPE_OPERATOR_MODULE         ||
            element->type == ELEMENT_TYPE_OPERATOR_POWER
            ) { // *, /, %, **
            ExpressionElement* lastELement1 = popExpressionStack(evaluateStack);
            ExpressionElement* lastElement2 = popExpressionStack(evaluateStack);

            if(lastELement1 != NULL && lastElement2 != NULL &&
                lastELement1->type == ELEMENT_TYPE_NUMBER && lastElement2->type == ELEMENT_TYPE_NUMBER
                ) {
                ExpressionElement* newElement =
                    performArithmeticOperation(lastElement2, lastELement1, element);
                pushExpressionStack(evaluateStack, newElement);
            } else {
                char errMsg[50];
                sprintf(errMsg, "'%s' operator was used incorrectly", element->value);
                showError(ERROR_SYNTAX, errMsg);
            }

        } else if(
            element->type == ELEMENT_TYPE_OPERATOR_LESS         ||
            element->type == ELEMENT_TYPE_OPERATOR_GREAT        ||
            element->type == ELEMENT_TYPE_OPERATOR_LESS_EQUAL   ||
            element->type == ELEMENT_TYPE_OPERATOR_GREAT_EQUAL
            ) { // <, >, <=, >=
            ExpressionElement* lastElement1 = popExpressionStack(evaluateStack);
            ExpressionElement* lastElement2 = popExpressionStack(evaluateStack);

            if(lastElement1 != NULL && lastElement2 != NULL &&
                lastElement1->type == ELEMENT_TYPE_NUMBER && lastElement2->type == ELEMENT_TYPE_NUMBER
                ) {
                ExpressionElement* newElement =
                    performComparisonOperation(lastElement2, lastElement1, element);
                pushExpressionStack(evaluateStack, newElement);
            } else {
                char errMsg[50];
                sprintf(errMsg, "'%s' operator was used incorrectly", element->value);
                showError(ERROR_SYNTAX, errMsg);
            }
        }
    }

    ExpressionElement* resultElement = popExpressionStack(evaluateStack); // stack result element

    freeExpressionStack(evaluateStack); // free memory

    return expressionElementToData(resultElement);
}

ExpressionElement*
performArithmeticOperation(ExpressionElement* o1, ExpressionElement* o2, ExpressionElement* operator) {

    double operand1 = atof(o1->value);
    double operand2 = atof(o2->value);
    char* result;

    switch(operator->type) {
        case ELEMENT_TYPE_OPERATOR_PLUS:
            result = doubleToString(operand1 + operand2);
            break;
        case ELEMENT_TYPE_OPERATOR_MINUS:
            result = doubleToString(operand1 - operand2);
            break;
        case ELEMENT_TYPE_OPERATOR_MULTIPLY:
            result = doubleToString(operand1 * operand2);
            break;
        case ELEMENT_TYPE_OPERATOR_DIVIDE:
            if(operand2 == 0)
                showError(ERROR_RUNTIME, "Division by zero");
            result = doubleToString(operand1 / operand2);
            break;
        case ELEMENT_TYPE_OPERATOR_MODULE:
            if(operand2 == 0)
                showError(ERROR_RUNTIME, "Modulus by zero");
            result = __uint128_tToString((int) operand1 % (int) operand2);
            break;
        case ELEMENT_TYPE_OPERATOR_POWER:
            result = doubleToString(pow(operand1, operand2));
            break;
        default:
            return NULL;
    }

    freeExpressionElement(o1);
    freeExpressionElement(o2);
    freeExpressionElement(operator);

    return createExpressionElement(ELEMENT_TYPE_NUMBER, result);
}

ExpressionElement*
performComparisonOperation(ExpressionElement* o1, ExpressionElement* o2, ExpressionElement* operator) {
    double operand1 = atof(o1->value);
    double operand2 = atof(o2->value);
    char* result;

    switch(operator->type) {
        case ELEMENT_TYPE_OPERATOR_LESS:
            result = boolToString(operand1 < operand2 ? true : false);
            break;
        case ELEMENT_TYPE_OPERATOR_GREAT:
            result = boolToString(operand1 > operand2 ? true : false);
            break;
        case ELEMENT_TYPE_OPERATOR_LESS_EQUAL:
            result = boolToString(operand1 <= operand2 ? true : false);
            break;
        case  ELEMENT_TYPE_OPERATOR_GREAT_EQUAL:
            result = boolToString(operand1 >= operand2 ? true : false);
            break;
        default:
            return NULL;
    }

    freeExpressionElement(o1);
    freeExpressionElement(o2);
    freeExpressionElement(operator);

    return createExpressionElement(ELEMENT_TYPE_BOOL, result);
}