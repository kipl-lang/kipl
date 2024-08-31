//
// Created by Kerem on 30/08/2024.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include "../dataType.h"
#include "../../token/token.h"

typedef struct _function {
    char* name;
    DataType returnType;
    //params düşün---
    Token* firstToken;
} Function;

Function* createFunction(char* name, DataType returnType, Token* firstToken);

#endif //FUNCTION_H
