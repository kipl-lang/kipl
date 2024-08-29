/**
 The Kipl Programming Language

 File: token/token.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include "token.h"

#include <stdio.h>

#include "stdlib.h"

Token* makeToken(TokenType type, char* value, char* fileName, unsigned int line, unsigned int column) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    token->fileName = fileName;
    token->line = line;
    token->column = column;
    token->next = NULL;

    return token;
}

Token* getLastToken(Token* token) {
    if(token->next == NULL)
        return token;

    return getLastToken(token->next);
}

Token* getLastTokenWithOutEOF(Token* token) {
    if(token->type == TOKEN_EOF)
        return NULL;

    if(token->next->type == TOKEN_EOF)
        return token;

    return getLastTokenWithOutEOF(token->next);
}

void freeTokens(Token* token) {
    Token* tempToken = token;

    while(tempToken != NULL) {
        Token* tempToken2 = tempToken;
        tempToken = tempToken->next;
        free(tempToken2);
    }
}