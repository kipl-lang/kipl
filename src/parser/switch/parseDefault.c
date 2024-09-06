//
// Created by Kerem on 06/09/2024.
//

#include "parseDefault.h"

#include "../global.h"
#include "../error/error.h"

void parseDefault() {
    if(currentSwitch != NULL) {
        currentToken = currentToken->next;

        if(currentToken->type == TOKEN_COLON) {
            currentToken = currentToken->next;
            caseStatus = true;
        } else {
            showError(ERROR_SYNTAX, "Expected ':' after default");
        }
    }
    else {
        showError(ERROR_SYNTAX, "Default is not in switch");
    }
}
