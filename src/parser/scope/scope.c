//
// Created by Kerem on 29/07/2024.
//

#include "scope.h"
#include "../global.h"
#include <stdlib.h>



void createScope() {
    Scope* scope = (Scope*) malloc(sizeof(Scope));
    scope->parentScope = currentScope;
    currentScope = scope;
}

void freeScope() {
    Scope* tempScope = currentScope;
    currentScope = currentScope->parentScope;
    //free variables
    free(tempScope);
}
