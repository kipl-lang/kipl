//
// Created by Kerem on 30/08/2024.
//

#include "function.h"

#include <stdlib.h>

Function* createFunction(char* name, DataType returnType, Token* firstToken) {
    Function* function = (Function*) malloc(sizeof(Function));
    function->name = name;
    function->returnType = returnType;
    function->firstToken = firstToken;

    return function;
}
