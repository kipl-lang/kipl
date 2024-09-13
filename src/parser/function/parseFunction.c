//
// Created by Kerem on 12/09/2024.
//

#include "parseFunction.h"

#include <stdio.h>
#include <string.h>

#include "../global.h"
#include "../error/error.h"
#include "../helpers/dataTypes/isFuncDataType.h"
#include "../helpers/dataTypes/getDataType.h"

void parseFunction() {
    currentToken = currentToken->next;
    if(currentToken->type == TOKEN_IDENTIFIER) { // func <func_name>
        char* funcName = currentToken->value;

        if(strlen(funcName) > 64) // The maximum length of the function name must be 64 characters
            showError(ERROR_SYNTAX, "The function name is too long");

        if(isFuncDeclared(funcName)) {
            char errMsg[256];
            sprintf(errMsg, "The function '%s' is already declared.", funcName);
            showError(ERROR_SYNTAX, errMsg);
        }

        currentToken = currentToken->next;
        if(currentToken->type == TOKEN_COLON) { // func <func_name>:
            currentToken = currentToken->next;
            if(isFuncDataType(currentToken->type)) { // func <func_name>: <return_type>
                DataType dataType = getDataType(currentToken->type);
                currentToken = currentToken->next;
                if(currentToken->type == TOKEN_ARROW) {
                    currentToken = currentToken->next;
                    //PARAMS PARSER YAIZLACAK
                } else {
                    showError(ERROR_SYNTAX, "Expected '=>' after func <func_name>: <return_type>");
                }
            } else {
                showError(ERROR_RUNTIME, "Expected <return_type> after func <func_name> :");
            }
        } else {
            showError(ERROR_SYNTAX, "Expected ':' after <func_name>");
        }
    } else {
        showError(ERROR_SYNTAX, "Expected <func_name> after func");
    }
}
