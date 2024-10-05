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


        if(funcReturnData != NULL)
             freeData(funcReturnData);
        funcReturnData = getData;
        funcOut();

    } else {
        showError(ERROR_RUNTIME, "return is not in a function");
    }
}

void returnTypeControl(Data* data) {

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