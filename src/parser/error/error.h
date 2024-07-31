//
// Created by Kerem on 31/07/2024.
//

#ifndef ERROR_H
#define ERROR_H

typedef enum _error_type {
    ERROR_LEXICAL,
    ERROR_SYNTAX,
    ERROR_RUNTIME,
} ErrorType;

void showError(ErrorType type, char* desc, unsigned int line, unsigned int column);

#endif //ERROR_H
