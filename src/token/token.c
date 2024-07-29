//
// Created by Kerem on 28/07/2024.
//

#include "token.h"i
#include "stdlib.h"

Token* makeToken(TokenType type, char* value, unsigned int line, unsigned int column) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->value = value;
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