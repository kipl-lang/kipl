//
// Created by Kerem on 30/08/2024.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdbool.h>

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
    Token* lastToken;
    struct _function* next;
} Function;

typedef struct _func_call_status {
    unsigned int lastOpenRoundBracket;
    unsigned int lastOpenCurlyBracket;
    struct _func_call_status* parentFuncCall;
} FuncCallStatus;

Params* createParam(char* name, DataType dataType);

void createFunction(char* name, DataType returnType, Params* params, Token* firstToken, Token* lastToken);

void createFuncCallStatus(unsigned int lastOpenRoundBracket, unsigned int lastOpenCurlyBracket);

void freeFuncCallStatus();

bool isFuncDeclared(char* funcName);

void funcDeclaredControl(const Function* func1, const Function* func2);

Function* getFunc(const char* name);

Token* getLastTokenFromFunc(Function* func);

void freeFunctions();

#endif //FUNCTION_H
