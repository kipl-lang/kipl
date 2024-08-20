/**
 The Kipl Programming Language

 File: main.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "lexer/lexer.h"
#include "parser/parser.h"

int main(void) {
    setlocale(LC_ALL, "en_US.UTF-8");

    char* string = "for true {var x :i32 = 2} var x:i32 = 54";
    Token* token =  scanner(string);
    parser(token);

    //system("pause");
    freeTokens(token); // free memory

    return 0;
}
