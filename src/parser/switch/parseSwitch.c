//
// Created by Kerem on 04/09/2024.
//

#include "parseSwitch.h"

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseSwitch() {
    unsigned int lastOpenCurlyBracket = openCurlyBracket;
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
        createSwitch(lastOpenCurlyBracket);
        openCurlyBracket++;
        createScope();
        currentToken = currentToken->next;
    } else {
        showError(ERROR_SYNTAX, " expected '{' after switch clause");
    }
}
