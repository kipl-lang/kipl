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

    char* string = "var _num: i8 var number2: i8 var number3: i8";
    Token* token =  scanner(string);
    parser(token);


    freeTokens(token); // free memory

    return 0;
}
