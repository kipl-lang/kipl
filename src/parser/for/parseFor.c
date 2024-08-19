//
// Created by Kerem on 18/08/2024.
//

#include "parseFor.h"

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"
#include "../variable/parseVariable.h"

void parseFor() {
    Token* forToken = currentToken;
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL && data->dataType == TYPE_BOOL) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {

        } else {
            showError(ERROR_SYNTAX, " expected '{' after for clause");
        }
    } else {
        showError(ERROR_SYNTAX, "non-boolean condition in for statement");
    }
}
