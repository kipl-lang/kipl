//
// Created by Kerem on 04/08/2024.
//

#include "Data.h"

#include "../global.h"
#include "../variable/variable.h"



Data* getDataFromVariable(char* name) {
    Scope* tempScope = currentToken;

    while(tempScope != NULL) {



        tempScope = tempScope->parentScope;
    }

    return NULL; // variable undefined
}