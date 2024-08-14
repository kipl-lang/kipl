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
    char* string = "var x:string var y:i8 =(-8  +(+9-6))";
    Token* token =  scanner(string);
    parser(token);

    //system("pause");
    freeTokens(token); // free memory

    return 0;
}
