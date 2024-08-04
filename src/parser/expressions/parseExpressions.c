//
// Created by Kerem on 04/08/2024.
//

#include "parseExpressions.h"
#include "../global.h",
#include "../../token/token.h"

Data* parseExpressions() {
    if(currentToken->type == TOKEN_EOF)
        return NULL;

    while(currentToken->type != TOKEN_EOF) {
        if(currentToken->type == TOKEN_IDENTIFIER) {

        }
    }

}
