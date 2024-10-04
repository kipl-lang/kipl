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
    DataType returnType;
    struct _func_call_status* parentFuncCall;
} FuncCallStatus;

typedef struct _is_expression_func {
    struct _is_expression_func* parent;
} IsExpressionFunc;

Params* createParam(char* name, DataType dataType);

void createFunction(char* name, DataType returnType, Params* params, Token* firstToken, Token* lastToken);

void createFuncCallStatus(unsigned int lastOpenRoundBracket, unsigned int lastOpenCurlyBracket, DataType returnType);

void freeFuncCallStatus();

void createIsExpressionFunc();

void freeIsExpressionFunc();

bool isFuncDeclared(char* funcName);

void funcDeclaredControl(const Function* func1, const Function* func2);

Function* getFunc(const char* name);

Token* getLastTokenFromFunc(Function* func);

Token* copyTokensFromFunc(Function* func);

void freeFunctions();

#endif //FUNCTION_H
