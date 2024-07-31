//
// Created by Kerem on 29/07/2024.
//

#include "parser.h"

#include <stdio.h>

#include "global.h"
#include "stdbool.h"

void parser(Token* token) {
    currentToken = token;

    while(currentToken->type != TOKEN_EOF) {
        printf(currentToken->value);


        if(currentToken->type == TOKEN_VAR)
            printf("kerem");
        currentToken = currentToken->next;
    }
}