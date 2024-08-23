//
// Created by Kerem on 20/08/2024.
//

#include "parseIdentifier.h"

#include <stdio.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/data.h"
#include "../expressions/parseExpressions.h"

void parseIdentifier() {
    if(!isVariableInAllScope(currentToken->value)) {
        char errMsg[256];
        sprintf(errMsg, "%s undefined", currentToken->value);
        showError(ERROR_RUNTIME, errMsg);
    }

    char* varName = currentToken->value;

    currentToken = currentToken->next;

    if(currentToken->type == TOKEN_EOF)
        return;

    if(currentToken->type == TOKEN_EQUAL) {
        currentToken = currentToken->next;
        Data* data = parseExpressions();
        if(data != NULL) {
            printf(data->value);
            assignToVariable(varName, data);
        } else {
            showError(ERROR_SYNTAX, "Expected <value> after <name> = ");
        }
    } else if(currentToken->type == TOKEN_PLUS_EQUAL) {
        currentToken = currentToken->next;
        Data* data = parseExpressions();
        if(data != NULL) {
            printf(data->value);

        } else {
            showError(ERROR_SYNTAX, "Expected <value> after var <name> : <type> = ");
        }
    } else {
        char errMsg[50];
        sprintf(errMsg, "%s is not used", varName);
        showError(ERROR_SYNTAX, errMsg);
    }
}
