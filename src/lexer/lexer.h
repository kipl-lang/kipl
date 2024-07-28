/**
 The Kipl Programming Language

 File: lexer/lexer.h

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"
#include "stdbool.h"

typedef struct _lexer {
    char* source;
    unsigned int position;
} Lexer;

Lexer* createLexer();

Token* scanner(const char* source);

bool isAtEnd();

bool isDigit();

bool isAlpha();

void freeLexer();
#endif //LEXER_H
