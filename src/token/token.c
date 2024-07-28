//
// Created by Kerem on 28/07/2024.
//

#include "token.h"
#include "stdlib.h"

Token* getLastToken(Token* token) {
    if(token->next == NULL)
        return token;

    return getLastToken(token->next);
}