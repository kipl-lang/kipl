/**
 The Kipl Programming Language

 File: main.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include <stdio.h>
#include <stdlib.h>

#include "lexer/lexer.h"
#include "parser/parser.h"

int main(void) {
    char* string = "var x:i8 var y:i8 = !true && false || true";
    Token* token =  scanner(string);
    parser(token);


    freeTokens(token); // free memory

    return 0;
}
