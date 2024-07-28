

#include "lexer.h"
#include <stdlib.h>
#include <string.h>

Lexer* lexer;

Token* scanner(const char* source) {
    lexer = createLexer(source);

    Token* firstToken = NULL;

    do {
        Token* tempToken = scanToken();

        if(firstToken == NULL)
            firstToken = tempToken;
        else
            getLastToken(firstToken)->next = tempToken;

    } while(getLastToken(firstToken)->type != TOKEN_EOF);

    freeLexer();
    return firstToken;
}

Lexer* createLexer(const char* source) {
    Lexer* lexer = (Lexer*)malloc(sizeof(Lexer));
    lexer->source = strdup(source);
    lexer->position = 0;

    return lexer;
}



bool isAtEnd() {
    return lexer->position == strlen(lexer->source);
}


void freeLexer() {
    if(lexer != NULL)
        free(lexer);
}