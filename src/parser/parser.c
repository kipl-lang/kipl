//
// Created by Kerem on 29/07/2024.
//

#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "stdbool.h"
#include "error/error.h"

void parser(Token* token) {
    currentToken = token;

    while(currentToken->type != TOKEN_EOF) {

        if(token->type == TOKEN_ERROR) {
            showError(ERROR_SYNTAX,"Unexpactede token", token->line,token->column);
        }


        if(currentToken->type == TOKEN_VAR)
            printf("kerem");
        currentToken = currentToken->next;
    }
}
