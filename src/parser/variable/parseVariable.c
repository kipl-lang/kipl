/**
 The Kipl Programming Language

 File: parser/variable/parseVariable.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include "parseVariable.h"
#include <stdio.h>
#include <string.h>
#include "../global.h"
#include "../../token/token.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"
#include "../helpers/dataTypes/isDataType.h"
#include "../helpers/dataTypes/getDataType.h"
#include "../expressions/data.h"

void parseVariable() {
    VarType varType;
    if(currentToken->type == TOKEN_CONST)
        varType = VAR_TYPE_CONST;
    else
        varType = VAR_TYPE_VAR;

    currentToken = currentToken->next;
    if(currentToken->type == TOKEN_IDENTIFIER) { // var name
        char* varName = currentToken->value;

        if(strlen(varName) > 64) // The maximum length of the variable name must be 64 characters
            showError(ERROR_SYNTAX, "The variable name is too long");

        if(isVariableInCurrentScope(varName ,currentScope)) {
            char errMsg[256];
            sprintf(errMsg, "The variable '%s' is already declared in this scope.", varName);
            showError(ERROR_SYNTAX, errMsg);
        }

        currentToken = currentToken->next;
        if(currentToken->type == TOKEN_COLON) { // var name:
            currentToken = currentToken->next;

            if(isDataType(currentToken->type)) { //var name: type
                DataType dataType = getDataType(currentToken->type);
                // create variable
                createVariable(dataType, varName, varType);
                currentToken = currentToken->next;
                if(currentToken->type == TOKEN_EQUAL) { // var name: type =
                    currentToken = currentToken->next;
                    Data* data = parseExpressions();
                    if(data != NULL) { // var name: type = value
                        assignToVariable(varName, data);
                    } else {
                        showError(ERROR_SYNTAX, "Expected <value> after var <name> : <type> = ");
                    }
                }
            } else {
                showError(ERROR_SYNTAX, "Expected <type> after var <name> : ");
            }
        } else {
            showError(ERROR_SYNTAX, "Expected : after var <name>");
        }
    } else {
        showError(ERROR_SYNTAX, "Expected <name> after var");
    }
}
