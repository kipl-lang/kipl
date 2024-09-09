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
            if(strcmp(newFunction->name, tempFunc->name) == 0) {
                char errMsg[256];
                sprintf(errMsg, "The function '%s' is already declared", newFunction->name);
                showError(ERROR_SYNTAX, errMsg);
            }
            tempFunc = tempFunc->next;
        }

        if(strcmp(newFunction->name, tempFunc->name) == 0)
            showError(ERROR_RUNTIME, "Function with this name is already.");

        tempFunc->next = newFunction;
    }
}
