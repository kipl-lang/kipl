/**
 The Kipl Programming Language

 File: File: parser/error/error.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/
#include "error.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../../include/colors.h"


void showError(ErrorType type, char* desc, unsigned int line, unsigned int column) {

    char* errorTitle;

    switch(type) {
        case ERROR_SYNTAX:
            errorTitle = "Syntax Error";
            break;
        case ERROR_LEXICAL:
            errorTitle = "Lexical Error";
            break;
        case ERROR_RUNTIME:
            errorTitle = "Runtime Error";
            break;
        default:
            errorTitle = "Unkown Error";
    }

    printf(RED "%s: %s\nLine: %d - Column: %d" RESET, errorTitle, desc, line, column);
    exit(EXIT_FAILURE);
}