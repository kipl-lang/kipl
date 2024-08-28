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
#include <string.h>

#include "lexer/lexer.h"
#include "parser/parser.h"
#include "parser/error/error.h"
#include "parser/helpers/file/readFile.h"

int main(int argc, const char* argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");

    if(argc != 2) { // Check if the user has provided a filename
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1]; // Get the filename
    size_t len = strlen(filename); // Get the length of the filename

    if(len < 6 || strcmp(filename + len - 5, ".kipl") != 0) { // Check if the file has a .kipl extension
        printf("File must have a .kipl extension\n");
        return 1;
    }

    char* string = readFile(filename);  //  kipl source code
    Token* token =  scanner(string);    //lexer
    parser(token);                      // parser

    //system("pause");
    freeTokens(token); // free memory

    return 0;
}
