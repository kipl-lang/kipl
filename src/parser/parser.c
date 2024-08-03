//
// Created by Kerem on 29/07/2024.
//

#include "parser.h"

#include "global.h"

#include "error/error.h"
#include "variable/parseVariable.h"
#include "scope/scope.h"

void parser(Token* token) {
    currentToken = token;   // Current Token
    createScope();          // Current Scope

    while(currentToken->type != TOKEN_EOF) {
        if(token->type == TOKEN_ERROR)
            showError(ERROR_SYNTAX,"Unexpected token");

        if(currentToken->type == TOKEN_VAR)
            parseVariable();
        //currentToken = currentToken->next;
    }

    freeScope();
}
