//
// Created by Kerem on 04/08/2024.
//

#include "parseExpressions.h"

#include <stdio.h>
#include <string.h>

#include "expressionQueue.h"
#include "expressionStack.h"
#include "../global.h"
#include "../../token/token.h"
#include "../error/error.h"

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
                enqueueExpression(queueOutput, element);
                openBracket++;
            } else if(element->type == ELEMENT_TYPE_BRACKET_R_R) {
                while(peekExpressionStack(stackOperator) != NULL &&
                    peekExpressionStack(stackOperator)->type != ELEMENT_TYPE_BRACKET_R_L
                    )
                    enqueueExpression(queueOutput, popExpressionStack(stackOperator));

                if(peekExpressionStack(stackOperator)->type == ELEMENT_TYPE_BRACKET_R_L) // pop '('
                    popExpressionStack(stackOperator);

                openBracket--;
            } else { // operator
                if(peekExpressionStack(stackOperator) == NULL)
                    pushExpressionStack(stackOperator, element);
                else {
                    if(getAssociativity(element) == ASSOCIATIVITY_LEFT) {
                        while(precedence(peekExpressionStack(stackOperator)) >= precedence(element)) {
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

    if(openBracket != 0)
        showError(ERROR_SYNTAX, "Brackets are not balanced");

    // After processing all tokens, pop any remaining operators from the stack and enqueue them
    while (peekExpressionStack(stackOperator) != NULL)
        enqueueExpression(queueOutput, popExpressionStack(stackOperator));


    freeExpressionStack(stackOperator); // free the stack
    freeExpressionQueue(queueOutput);   // free the queue
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

ExpressionElement* tokenToExpressionElement() {
    ExpressionElementType type;

    switch(currentToken->type) {
        case TOKEN_TYPE_I8:
        case TOKEN_TYPE_I16:
        case TOKEN_TYPE_I32:
        case TOKEN_TYPE_I64:
        case TOKEN_TYPE_I128:
        case TOKEN_TYPE_U8:
        case TOKEN_TYPE_U16:
        case TOKEN_TYPE_U32:
        case TOKEN_TYPE_U64:
        case TOKEN_TYPE_U128:
        case TOKEN_TYPE_F32:
        case TOKEN_TYPE_F64:
            type = ELEMENT_TYPE_NUMBER;
            break;
        case TOKEN_TYPE_BOOL:
            type = ELEMENT_TYPE_BOOL;
            break;
        case TOKEN_TYPE_STRING:
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
            type = ELEMENT_TYPE_OPERATOR_DIVIDE;
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