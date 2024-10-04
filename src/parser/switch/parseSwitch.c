//
// Created by Kerem on 04/09/2024.
//

#include "parseSwitch.h"

#include <stdio.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseSwitch() {
    unsigned int lastOpenCurlyBracket = openCurlyBracket;
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            createSwitch(data, lastOpenCurlyBracket);
            openCurlyBracket++;
            createScope();
            currentToken = currentToken->next;
        } else {
            showError(ERROR_SYNTAX, "Expected '{' after switch clause");
        }
    } else {
        showError(ERROR_SYNTAX, "Expected <value> after switch ");
    }
}
