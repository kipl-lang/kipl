//
// Created by Kerem on 05/09/2024.
//

#include "parseCase.h"

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseCase() {
    if(currentSwitch != NULL) {
        currentToken = currentToken->next;
        Data* data = parseExpressions();

        if(data != NULL) {
            if(currentToken->type == TOKEN_COLON) {
                currentToken = currentToken->next;
            } else {
                showError(ERROR_SYNTAX, "Exprected ':' after <value>");
            }
        } else {
            showError(ERROR_SYNTAX, "Expected <value> after case");
        }
    } else {
        showError(ERROR_SYNTAX, "Case is not in switch");
    }
}
