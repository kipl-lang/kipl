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

    char* string = "var x: u8 = -5 var y: i32 = 6 var t: f32 x **=2 var p:i32";
    Token* token =  scanner(string);
    parser(token);

    //system("pause");
    freeTokens(token); // free memory

    return 0;
}
