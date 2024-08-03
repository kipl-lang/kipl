//
// Created by Kerem on 31/07/2024.
//

#include "parseVariable.h"
#include "../global.h"
#include "../../token/token.h"
#include "../error/error.h"
#include "../helpers/dataTypes/isDataType.h"

void parseVariable() {
    currentToken = currentToken->next;
    if(currentToken->type == TOKEN_IDENTIFIER) { // var name
        // o isismle tanımlanmış değişken var mı kontrol et
        char* varName = currentToken->value;
        currentToken = currentToken->next;
        if(currentToken->type == TOKEN_COLON) { // var name:
            currentToken = currentToken->next;
            if(isDataType(currentToken->type)) { //var name: type
                // create variable
                currentToken = currentToken->next;
                if(currentToken->type == TOKEN_EQUAL) { // var name: type =
                   currentToken = currentToken->next;
                }
            } else {
                showError(ERROR_SYNTAX, "Expected : after var name");
            }
        } else {
            showError(ERROR_SYNTAX, "Expected : after var name");
        }
    } else {
        showError(ERROR_SYNTAX, "Expected identifier after var");
    }
}
