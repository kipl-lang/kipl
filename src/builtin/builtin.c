//
// Created by Kerem on 10/09/2024.
//

#include "builtin.h"
#include "stdlib.h"
#include "../parser/function/function.h"

void builtin() {
    Token* tempToken;
    Token* tempToken2;

    Token* firstToken = makeToken(TOKEN_BRACKET_CURLY_LEFT, "{", "stdin", 0, 0);

    tempToken = makeToken(TOKEN_OUT, "out", "stdin", 0, 0);
    firstToken->next = tempToken;

    tempToken2 = makeToken(TOKEN_STRING_LITERAL, "Hello World!", "stdin", 0, 0);
    tempToken->next = tempToken2;

    tempToken = makeToken(TOKEN_BRACKET_CURLY_RIGHT, "}", "stdin", 0, 0);
    tempToken2->next = tempToken;

    createFunction("kipl", TYPE_VOID, NULL, firstToken, tempToken);
}

