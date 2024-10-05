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
    bool isError = false;

    if(data != NULL) {
        switch(data->dataType) {
            case TYPE_F64:
                switch (returnType) {
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
                        return;
                    default:
                        isError = true;
                }
            break;
            case TYPE_BOOL:
                if(returnType == TYPE_BOOL)
                    return;
            isError = true;
            break;
            case TYPE_STRING:
                if(returnType == TYPE_STRING)
                    return;
            isError = true;
            break;
        }
    } else {
        if(returnType != TYPE_VOID)
            isError = true;
    }

    if(isError)
        showError(ERROR_RUNTIME, "Hatalı return");

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