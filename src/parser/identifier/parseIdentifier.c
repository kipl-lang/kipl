//
// Created by Kerem on 20/08/2024.
//

#include "parseIdentifier.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/data.h"
#include "../expressions/parseExpressions.h"
#include "../helpers/typeConversion/toString.h"

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
            showError(ERROR_SYNTAX, "Expected <value> after var <name> : <type> = ");
        }
    } else if(currentToken->type == TOKEN_PLUS_EQUAL) {
        currentToken = currentToken->next;
        Data* data = parseExpressions();
        Data* lastData = getDataFromVariable(varName);

        if(data != NULL) {
            if(data->dataType == TYPE_STRING) {
                char newValue[strlen(lastData->value) + strlen(data->value) + 1];
                sprintf(newValue, "%s%s", lastData->value, data->value);
                assignToVariable(varName, createData(TYPE_STRING, strdup(newValue)));
            } else if(dataTypeIsNumber(lastData->dataType) && dataTypeIsNumber(data->dataType)) {
                double operand1 = atof(lastData->value);
                double operand2 = atof(data->value);
                char* result = doubleToString(operand1 + operand2);
                assignToVariable(varName, createData(TYPE_F64, result));
            }
        } else {
            showError(ERROR_SYNTAX, "Expected <value> after <name>  = ");
        }

        freeData(lastData);
        freeData(data);
    } else {
        char errMsg[50];
        sprintf(errMsg, "%s is not used", varName);
        showError(ERROR_SYNTAX, errMsg);
    }
}
