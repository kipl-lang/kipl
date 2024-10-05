//
// Created by Kerem on 30/09/2024.
//

#include "parseReturn.h"

#include <stdio.h>
#include <stdlib.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseReturn() {
    if(currentFuncCallStatus != NULL) {
        currentToken = currentToken->next;
        Data* getData = parseExpressions();
        returnTypeControl(getData);

        if(funcReturnData != NULL)
             freeData(funcReturnData);
        funcReturnData = getData;
        funcOut();

    } else {
        showError(ERROR_RUNTIME, "return is not in a function");
    }
}

void returnTypeControl(Data* data) {

    DataType returnType = currentFuncCallStatus->returnType;

    switch(returnType) {
        case TYPE_I8:
            if(dataTypeIsNumber(data->dataType)) {
                int8_t dataValue = (int8_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_I16:
            if(dataTypeIsNumber(data->dataType)) {
                int16_t dataValue = (int16_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_I32:
            if(dataTypeIsNumber(data->dataType)) {
                int32_t dataValue = (int32_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_I64:
            if(dataTypeIsNumber(data->dataType)) {
                int64_t dataValue = (int64_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_I128:
            if(dataTypeIsNumber(data->dataType)) {
                __int128_t dataValue = (__int128_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_U8:
            if(dataTypeIsNumber(data->dataType)) {
                uint8_t dataValue = (uint8_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_U16:
            if(dataTypeIsNumber(data->dataType)) {
                uint16_t dataValue = (uint16_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_U32:
            if(dataTypeIsNumber(data->dataType)) {
                uint32_t dataValue = (uint32_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_U64:
            if(dataTypeIsNumber(data->dataType)) {
                uint64_t dataValue = (uint64_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_U128:
            if(dataTypeIsNumber(data->dataType)) {
                __uint128_t dataValue = (__uint128_t) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_F32:
            if(dataTypeIsNumber(data->dataType)) {
                float dataValue = (float) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_F64:
            if(dataTypeIsNumber(data->dataType)) {
                double dataValue = (double) atof(data->value);
                if(atof(data->value) == dataValue)
                    return;
                showError(ERROR_RUNTIME, "invalid value range");
            } else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            break;
        case TYPE_BOOL:
            if(data->dataType == TYPE_BOOL)
                return;
            else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a boolean expression", data->value);
                showError(ERROR_RUNTIME, errMsg);
                break;
            }
        case TYPE_STRING:
            if(data->dataType == TYPE_STRING)
                return;
            else {
                char* errMsg[50];
                sprintf(errMsg, "%s is not a string", data->value);
                showError(ERROR_RUNTIME, errMsg);
                break;
            }
        case TYPE_VOID:
            if(data == NULL)
                return;
            char* errMsg[50];
            sprintf(errMsg, "%s is not a void", data->value);
            showError(ERROR_RUNTIME, errMsg);
            break;
    }

}

void funcOut() { // fonksiyonun kapanış süslü paranteznine götür
    while(currentToken->type != TOKEN_EOF) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT)
            openCurlyBracket++;
        else if(currentToken->type == TOKEN_BRACKET_CURLY_RIGHT) {
            if(openCurlyBracket == currentFuncCallStatus->lastOpenCurlyBracket+1)
                break;
            openCurlyBracket--;
        }

        currentToken = currentToken->next;
    }
}