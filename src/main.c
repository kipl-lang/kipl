/**
 The Kipl Programming Language

 File: main.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include <stdio.h>
#include <stdlib.h>

#include "lexer/lexer.h"

int main(void) {

    char* string = "**=";
    Token* token =  scanner(string);

    while(token->type != TOKEN_EOF) {
        printf(token->value);
        printf("%d ", token->line);
        printf("%d\n", token->column);
        token = token->next;
    }

    freeTokens(token);
}
