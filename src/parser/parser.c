/**
 The Kipl Programming Language

 File: parser/parser.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

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
            showError(ERROR_SYNTAX, token->value);

        if(currentToken->type == TOKEN_VAR)
            parseVariable();
        //currentToken = currentToken->next;
    }

    freeScope();
}
