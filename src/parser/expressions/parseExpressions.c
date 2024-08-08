//
// Created by Kerem on 04/08/2024.
//

#include "parseExpressions.h"

#include <stdio.h>

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
                return data;
            } else { // variable is not defined
                char errMsg[256];
                sprintf(errMsg, "%s undefined", currentToken->value);
                showError(ERROR_RUNTIME, errMsg);
            }
        }
    }
    return NULL;
}

// int precedence(ExpressionElement* element) {
//     switch(element->type) {
//         case
//     }
// }