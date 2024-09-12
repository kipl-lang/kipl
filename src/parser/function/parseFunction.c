//
// Created by Kerem on 12/09/2024.
//

#include "parseFunction.h"

#include "../global.h"
#include "../error/error.h"

void parseFunciton() {
    currentToken = currentToken->next;
    if(currentToken->type == TOKEN_IDENTIFIER) {
        char* funcName = currentToken->value;
    } else {
        showError(ERROR_SYNTAX, "Expected <func_name> after func");
    }
}
