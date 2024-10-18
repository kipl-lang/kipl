//
// Created by Kerem on 11/10/2024.
//

#include "outln.h"
#include "../../parser/function/function.h"

void outln() {
    Token* firstToken;
    Token* tempToken;
    Token* tempToken2;

    firstToken = makeToken(TOKEN_BRACKET_CURLY_LEFT, "{", "stdin", 0, 0);

    tempToken = makeToken(TOKEN_OUT, "out", "stdin", 0, 0);
    firstToken->next = tempToken;


}
