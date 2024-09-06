//
// Created by Kerem on 05/09/2024.
//

#include "parseCase.h"

#include <stdio.h>
#include <string.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseCase() {
    if(currentSwitch != NULL) {
        currentToken = currentToken->next;
        Data* data = parseExpressions();

        if(data != NULL) {
            if((dataTypeIsNumber(data->dataType) && dataTypeIsNumber(currentSwitch->data->dataType)) ||
                (data->dataType == TYPE_BOOL && currentSwitch->data->dataType == TYPE_BOOL) ||
                (data->dataType == TYPE_STRING && currentSwitch->data->dataType == TYPE_STRING)
                ) {
                if(currentToken->type == TOKEN_COLON) {
                    currentToken = currentToken->next;
                    if(!strcmp(data->value, currentSwitch->data->value)) {
                        caseStatus = true;
                    } else {
                        while(currentToken->type != TOKEN_EOF && currentToken->type != TOKEN_CASE &&
                            currentToken->type != TOKEN_DEFAULT
                            ) {
                            if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT)
                                openCurlyBracket++;
                            else if(currentToken->type == TOKEN_BRACKET_CURLY_RIGHT) {
                                if(openCurlyBracket == currentSwitch->lastBracketsNumber+1)
                                    break;
                                openCurlyBracket--;
                            }

                            currentToken = currentToken->next;
                        }
                    }
                } else {
                    showError(ERROR_SYNTAX, "Expected ':' after <value>");
                }
            } else {
                showError(ERROR_RUNTIME,
                    "The type of the switch expression does not match the type of the case value.");
            }
        } else {
            showError(ERROR_SYNTAX, "Expected <value> after case");
        }
    } else {
        showError(ERROR_SYNTAX, "Case is not in switch");
    }
}
