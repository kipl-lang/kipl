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

#include <stdio.h>

#include "global.h"

#include "error/error.h"
#include "if/parseIf.h"
#include "variable/parseVariable.h"
#include "scope/scope.h"

void parser(Token* token) {
    currentToken = token;   // Current Token
    createScope();          // Current Scope

    while(currentToken->type != TOKEN_EOF) {
        if(currentToken->type == TOKEN_ERROR)
            showError(ERROR_SYNTAX, token->value);
        else if(currentToken->type == TOKEN_VAR)
            createScope();
        else if(currentToken->type == TOKEN_IF)
            parseIf();
        else
            showError(ERROR_SYNTAX, "unkown syntax");
        //currentToken = currentToken->next;
    }

    freeScope();
}
