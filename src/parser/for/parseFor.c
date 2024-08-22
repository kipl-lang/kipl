//
// Created by Kerem on 18/08/2024.
//

#include "parseFor.h"

#include <stdio.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"
#include "../helpers/typeConversion/toBool.h"
#include "../variable/parseVariable.h"

// Todo: if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) { bu ifadedden sonra openCurlyBracket++; koy
// Todo: else içerisinde null olmadığı sürece gez ve eğer type curly right ise ve lastopen +1 == openCrlr ise
void parseFor() {
    Token* forToken = currentToken;
    unsigned int lastOpenCurlyBracket = openCurlyBracket;
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL && data->dataType == TYPE_BOOL) {
        if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            openCurlyBracket++;
            currentToken = currentToken->next;
            if(stringToBool(data->value)) {
                createFor(forToken, lastOpenCurlyBracket);
                createScope();
            } else {
                while(currentToken->type != TOKEN_EOF) {
                    if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT)
                        openCurlyBracket++;
                    else if(currentToken->type == TOKEN_BRACKET_CURLY_RIGHT) {
                        openCurlyBracket--;
                        if(openCurlyBracket == lastOpenCurlyBracket) {
                            currentToken = currentToken->next;
                            break;
                        }
                    }
                    currentToken = currentToken->next;
                }
            }
        } else {
            showError(ERROR_SYNTAX, "expected '{' after for clause");
        }
    } else {
        showError(ERROR_SYNTAX, "non-boolean condition in for statement");
    }
}