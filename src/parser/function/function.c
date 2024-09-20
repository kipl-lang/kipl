//
// Created by Kerem on 30/08/2024.
//

#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../global.h"
#include "../error/error.h"

Params* createParam(char* name, DataType dataType) {
    Params* param = (Params*) malloc(sizeof(Params));
    param->name = name;
    param->dataType = dataType;
    param->next = NULL;

    return param;
}

void createFunction(char* name, DataType returnType, Params* params, Token* firstToken) {
    Function* newFunction = (Function*) malloc(sizeof(Function));
    newFunction->name = strdup(name);
    newFunction->returnType = returnType;
    newFunction->params = params;
    newFunction->firstToken = firstToken;
    newFunction->next = NULL;

    if(functions == NULL) {
        functions = newFunction;
    }
    else {
        Function* tempFunc = functions;
        while(tempFunc->next != NULL) {
            funcDeclaredControl(newFunction, tempFunc);
            tempFunc = tempFunc->next;
        }

        funcDeclaredControl(newFunction, tempFunc);

        tempFunc->next = newFunction;
    }
}

void createFuncCallStatus(unsigned int lastOpenRoundBrackets) {
    FuncCallStatus* newFuncCallStatus = (FuncCallStatus*) malloc(sizeof(FuncCallStatus));
    newFuncCallStatus->lastOpenRoundBrackets = lastOpenRoundBrackets;
    newFuncCallStatus->parentFuncCall = currentFuncCallStatus;
    currentFuncCallStatus = newFuncCallStatus;
}

void freeFuncCallStatus() {
    FuncCallStatus* tempFCS = currentFuncCallStatus;
    currentFuncCallStatus = currentFuncCallStatus->parentFuncCall;
    free(tempFCS);
}

void funcDeclaredControl(const Function* func1, const Function* func2) {
    if(strcmp(func1->name, func2->name) == 0) {
        char errMsg[256];
        sprintf(errMsg, "The function '%s' is already declared", func1->name);
        showError(ERROR_SYNTAX, errMsg);
    }
}

bool isFuncDeclared(char* funcName) {
    Function* tempFunc = functions;

    while(tempFunc != NULL) {
        if(!strcmp(funcName, tempFunc->name))
            return true;
        tempFunc = tempFunc->next;
    }

    return false;
}

Function* getFunc(const char* name) {
    Function* tempFunc = functions;

    while(tempFunc != NULL) {
        if(!strcmp(name, tempFunc->name))
            return tempFunc;
        tempFunc = tempFunc->next;
    }
    return NULL;
}

Token* getLastTokenFromFunc(Function* func) {
    Token* tempToken = func->firstToken;

    while(tempToken->next != NULL) {
        printf(tempToken->value);
        tempToken = tempToken->next;
    }
    return tempToken;
}

void freeFunctions() {
    while(functions != NULL) {
        Function* tempFunc = functions;
        functions = functions->next;
        while(tempFunc->params != NULL) {
            Params* tempParam = tempFunc->params;
            tempFunc->params = tempFunc->params->next;
            free(tempParam);
        }
        // İNCelenecek
        // while(tempFunc->firstToken != NULL) {
        //     Token* tempToken = tempFunc->firstToken;
        //     tempFunc->firstToken = tempFunc->firstToken->next;
        //     free(tempToken);
        // }
        free(tempFunc->name);
        free(tempFunc);
    }
}