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
            parseVariable();

        else if(currentToken->type == TOKEN_IF)
            parseIf();

        else if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            createScope();
            openCurlyBracket++;
            currentToken = currentToken->next;
        }
        else if(currentToken->type == TOKEN_BRACKET_CURLY_RIGHT) {
            if(openCurlyBracket == 0)
                showError(ERROR_SYNTAX, "Curly brackets are not balanced");

            openCurlyBracket--;
            freeScope();
            currentToken = currentToken->next;
        }
        else
            showError(ERROR_SYNTAX, "unkown syntax");
        //currentToken = currentToken->next;
    }

    if(openCurlyBracket != 0) // açılan curly brackets kapanmadıysa
        showError(ERROR_SYNTAX, "Curly brackets are not balanced");

    freeScope();
}
