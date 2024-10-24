//
// Created by Kerem on 18/08/2024.
//

#include "parseFor.h"

#include <stdio.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"
#include "../helpers/typeConversion/toBool.h"

void parseFor() {
    Token* forToken = currentToken;
    unsigned int lastOpenCurlyBracket = openCurlyBracket;
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL && data->dataType == TYPE_BOOL) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            openCurlyBracket++;
            currentToken = currentToken->next;
            if(stringToBool(data->value)) {
                freeData(data);
                createFor(forToken, lastOpenCurlyBracket);
                createScope();
            } else {
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
        } else {
            showError(ERROR_SYNTAX, "expected '{' after for clause");
        }
    } else {
        showError(ERROR_SYNTAX, "non-boolean condition in for statement");
    }
}