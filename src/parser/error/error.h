/**
 The Kipl Programming Language

 File: parser/error/error.h

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#ifndef ERROR_H
#define ERROR_H

typedef enum _error_type {
    ERROR_LEXICAL,
    ERROR_SYNTAX,
    ERROR_RUNTIME,
} ErrorType;

void showError(ErrorType type, char* desc);

#endif //ERROR_H
