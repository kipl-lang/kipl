//
// Created by Kerem on 17/08/2024.
//

#include "parseIf.h"

#include <stdio.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"
#include "../helpers/typeConversion/toBool.h"

void parseIf() {
    unsigned int lastOpenCurlyBracket = openCurlyBracket;
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL && data->dataType == TYPE_BOOL) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            openCurlyBracket++;
            currentToken = currentToken->next;
            if(stringToBool(data->value)) {
                createTrueBlock(lastOpenCurlyBracket);
                createScope();
            } else {
                skipFalse(lastOpenCurlyBracket);
            }
        } else {
            showError(ERROR_SYNTAX, " expected '{' after if clause");
        }
    } else {
        showError(ERROR_SYNTAX, "non-boolean condition in if statement");
    }
}

void skipFalse(unsigned int lastOpenCurlyBracket) {
    while(currentToken->type != TOKEN_EOF) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT)
            openCurlyBracket++;
        else if(currentToken->type == TOKEN_BRACKET_CURLY_RIGHT) {
            openCurlyBracket--;
            if(openCurlyBracket == lastOpenCurlyBracket) {
                currentToken = currentToken->next;
                break;
            }
        }
        currentToken = currentToken->next;
    }
}