//
// Created by Kerem on 18/08/2024.
//

#include "parseFor.h"

#include <stdio.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"
#include "../helpers/typeConversion/toBool.h"
#include "../variable/parseVariable.h"

void parseFor() {
    Token* forToken = currentToken;
    unsigned int lastOpenCurlyBracket = openCurlyBracket;
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL && data->dataType == TYPE_BOOL) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            if(stringToBool(data->value)) {
                createFor(forToken, lastOpenCurlyBracket);
                createScope();
                openCurlyBracket++;
                currentToken = currentToken->next;
            } else {
                while(currentToken != NULL && currentToken->type != TOKEN_BRACKET_CURLY_RIGHT) {
                    if(currentToken->type == TOKEN_EOF)
                        break;
                    currentToken = currentToken->next;
                }
                if(currentToken != NULL && currentToken->type == TOKEN_BRACKET_CURLY_RIGHT)
                    currentToken = currentToken->next;
            }
        } else {
            showError(ERROR_SYNTAX, "expected '{' after for clause");
        }
    } else {
        showError(ERROR_SYNTAX, "non-boolean condition in for statement");
    }
}
