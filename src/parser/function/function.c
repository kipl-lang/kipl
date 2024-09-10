//
// Created by Kerem on 30/08/2024.
//

#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../global.h"
#include "../error/error.h"

void createFunction(char* name, DataType returnType, Token* firstToken) {
    Function* newFunction = (Function*) malloc(sizeof(Function));
    newFunction->name = name;
    newFunction->returnType = returnType;
    newFunction->firstToken = firstToken;
    newFunction->next = NULL;

    if(functions == NULL)
        functions = newFunction;
    else {
        Function* tempFunc = functions;
        while(functions->next != NULL) {
            funcDeclaredControl(newFunction, tempFunc);
            tempFunc = tempFunc->next;
        }

        funcDeclaredControl(newFunction, tempFunc);

        tempFunc->next = newFunction;
    }
}


void funcDeclaredControl(const Function* func1, const Function* func2) {
    if(strcmp(func1->name, func2->name) == 0) {
        char errMsg[256];
        sprintf(errMsg, "The function '%s' is already declared", func1->name);
        showError(ERROR_SYNTAX, errMsg);
    }
}

void freeFunctions() {
    while(functions != NULL) {
        Function* tempFunc = functions;
        functions = functions->next;
        while(tempFunc->params != NULL) {
            Params* tempParam = tempFunc->params;
            tempFunc->params = tempFunc->params->next;
            free(tempParam->data);
            free(tempParam);
        }
        free(tempFunc);
    }
}