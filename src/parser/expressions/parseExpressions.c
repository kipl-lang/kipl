//
// Created by Kerem on 04/08/2024.
//

#include "parseExpressions.h"

#include <stdio.h>

#include "../global.h",
#include "../../token/token.h"
#include "../error/error.h"

Data* parseExpressions() {
    if(currentToken->type == TOKEN_EOF)
        return NULL;

    while(currentToken->type != TOKEN_EOF) {
        if(currentToken->type == TOKEN_IDENTIFIER) {
            Data* data = getDataFromVariable(currentToken->value);
            if(data != NULL) {
                printf(data->value);
            } else {
                char errMsg[256];
                sprintf(errMsg, "%s undefined", currentToken->value);
                showError(ERROR_RUNTIME, errMsg);
            }
        }
    }

}
