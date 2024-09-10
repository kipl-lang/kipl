//
// Created by Kerem on 30/08/2024.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include "../dataType.h"
#include "../../token/token.h"

typedef struct _params {
    DataType dataType;
    char* name;
    struct _params* next;
} Params;

typedef struct _function {
    char* name;
    DataType returnType;
    Params* params;
    Token* firstToken;
    struct _function* next;
} Function;

void createFunction(char* name, DataType returnType, Params* params, Token* firstToken);

void funcDeclaredControl(const Function* func1, const Function* func2);

void freeFunctions();

#endif //FUNCTION_H
