//
// Created by Kerem on 18/08/2024.
//

#include "parseFor.h"

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"
#include "../helpers/typeConversion/toBool.h"
#include "../variable/parseVariable.h"

void parseFor() {
    createFor(currentToken, openCurlyBracket);
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL && data->dataType == TYPE_BOOL) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            if(!stringToBool(data->value)) {
                while(currentToken->type != TOKEN_BRACKET_CURLY_RIGHT) {
                    if(currentToken->type == TOKEN_EOF)
                        break;
                    currentToken = currentToken->next;
                }

                if(currentToken->type == TOKEN_BRACKET_CURLY_RIGHT) {
                    openCurlyBracket--;
                    For* tempFor = currentFor;
                    currentFor = currentFor->parentFor;
                    freeFor(tempFor);
                    currentToken = currentToken->next;
                }
            }
        } else {
            showError(ERROR_SYNTAX, " expected '{' after for clause");
        }
    } else {
        showError(ERROR_SYNTAX, "non-boolean condition in for statement");
    }
}
