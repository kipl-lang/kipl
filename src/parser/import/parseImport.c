//
// Created by Kerem on 25/08/2024.
//

#include "parseImport.h"

#include "../global.h"
#include "../error/error.h"

void parseImport() {
    currentToken = currentToken->next;

    if(currentToken->type == TOKEN_STRING_LITERAL) {

    } else {
        showError(ERROR_SYNTAX, "Expected \"<file>\" after import");
    }
}
