//
// Created by Kerem on 12/09/2024.
//

#include "parseFunction.h"

#include <stdio.h>
#include <string.h>

#include "../global.h"
#include "../error/error.h"
#include "../helpers/dataTypes/isFuncDataType.h"

void parseFunciton() {
    currentToken = currentToken->next;
    if(currentToken->type == TOKEN_IDENTIFIER) {
        char* funcName = currentToken->value;

        if(strlen(funcName) > 64) // The maximum length of the function name must be 64 characters
            showError(ERROR_SYNTAX, "The function name is too long");

        if(isFuncDeclared(funcName)) {
            char errMsg[256];
            sprintf(errMsg, "The function '%s' is already declared.", funcName);
            showError(ERROR_SYNTAX, errMsg);
        }

        currentToken = currentToken->next;
        if(currentToken->type == TOKEN_COLON) {
            currentToken = currentToken->next;
            if(isFuncDataType(currentToken->type)) {

            } else {
                showError(ERROR_RUNTIME, "Expected <type> after func <func_name> :");
            }
        } else {
            showError(ERROR_SYNTAX, "Expected ':' after <func_name>");
        }

        printf("hello");

    } else {
        showError(ERROR_SYNTAX, "Expected <func_name> after func");
    }
}
