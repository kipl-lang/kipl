//
// Created by Kerem on 17/08/2024.
//

#include "parseIf.h"

#include <stdio.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseIf() {
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL && data->dataType == TYPE_BOOL) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            createScope();
            openCurlyBracket++;
            currentToken = currentToken->next;
        } else {
            showError(ERROR_SYNTAX, " expected '{' after if clause");
        }
    } else {
        showError(ERROR_SYNTAX, "non-boolean condition in if statement");
    }
}
