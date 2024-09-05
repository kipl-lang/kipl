//
// Created by Kerem on 05/09/2024.
//

#include "parseCase.h"

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseCase() {
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL) {

    } else {
        showError(ERROR_SYNTAX, "Expected <value> after case");
    }
}
