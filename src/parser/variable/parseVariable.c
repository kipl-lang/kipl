//
// Created by Kerem on 31/07/2024.
//

#include "parseVariable.h"
#include "../global.h"
#include "../../token/token.h"

void parseVariable() {
    if(currentToken->type ==  TOKEN_VAR) { // var
        currentToken = currentToken->next;
        if(currentToken->type == TOKEN_IDENTIFIER) {
            char* varName = currentToken->value;
        }
    }
}