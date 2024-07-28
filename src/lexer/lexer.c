

#include "lexer.h"

#include <stdlib.h>
#include <string.h>

Lexer* lexer;

Token* scanner(const char* source) {
    lexer = createLexer(source);

    while() {

    }
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

