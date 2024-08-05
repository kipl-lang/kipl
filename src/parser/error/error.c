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

#include "../global.h"
#include "../../../include/colors.h"

// ToDo : Hata durumunda program sonlanıyor bellekte tahsis edilen alan serbest bırakılmıyor. Bu durumu düzelt
void showError(ErrorType type, char* desc) {

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

    printf(RED "\n%s: %s\nLine: %d - Column: %d \n" RESET, errorTitle, desc, currentToken->line, currentToken->column);
    exit(EXIT_FAILURE);
}
