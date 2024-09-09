//
// Created by Kerem on 30/08/2024.
//

#include "function.h"
#include <stdlib.h>
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
        while(tempFunc->next != NULL) {
            if(newFunction->name == tempFunc->name)
                showError(ERROR_RUNTIME, "Function with this name is alread");
            tempFunc = tempFunc->next;
        }
        tempFunc->next = newFunction;
    }
}
