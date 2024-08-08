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
    // if(currentToken->type == TOKEN_EOF)
    //     return NULL;

    while(currentToken->type != TOKEN_EOF) {
        // Todo: Shunting yard algoritmasıyla expressionları postfize çevir ve strinbg duurmlarını ds düşün
        ExpressionStack* stackOperator = createExpressionStack();
        ExpressionQueue* queueOutput = createExpressionQueue();

        if(currentToken->type == TOKEN_IDENTIFIER) {
            Data* data = getDataFromVariable(currentToken->value);
            if(data != NULL) {

            } else { // variable is not defined
                char errMsg[256];
                sprintf(errMsg, "%s undefined", currentToken->value);
                showError(ERROR_RUNTIME, errMsg);
            }
        }
    }
    return NULL;
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
    }

    freeData(data);
    return createExpressionElement(type, value);
}

// int precedence(ExpressionElement* element) {
//     switch(element->type) {
//         case
//     }
// }