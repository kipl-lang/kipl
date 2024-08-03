/**
 The Kipl Programming Language

 File: parser/scope/scope.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/


#include "scope.h"
#include "../global.h"
#include <stdlib.h>


void createScope() {
    Scope* scope = (Scope*) malloc(sizeof(Scope));
    scope->i8Variable = NULL;
    scope->i16Variable = NULL;
    scope->i32Variable = NULL;
    scope->i64Variable = NULL;
    scope->i128Variable = NULL;
    scope->u8Variable = NULL;
    scope->u16Variable = NULL;
    scope->u32Variable = NULL;
    scope->u64Variable = NULL;
    scope->u128Variable = NULL;
    scope->f32Variable = NULL;
    scope->f64Variable = NULL;
    scope->boolVariable = NULL;
    scope->stringVariable = NULL;
    scope->parentScope = currentScope;
    currentScope = scope;
}

void freeScope() {
    // free variable
    freeI8Variables();
    freeI16Variables();
    freeI32Variables();
    freeI64Variables();
    freeI128Variables();
    freeU8Variables();
    freeU16Variables();
    freeU32Variables();
    freeU64Variables();
    freeU128Variables();
    freeF32Variables();
    freeF64Variables();
    freeBoolVariables();
    freeStringVariables();

    // free scope
    Scope* tempScope = currentScope;
    currentScope = currentScope->parentScope;
    free(tempScope);
}

void freeI8Variables() {
    while(currentScope->i8Variable != NULL) {
        I8Variable* tempVar = currentScope->i8Variable;
        currentScope->i8Variable = tempVar->next;
        free(tempVar);
    }
}

void freeI16Variables() {
    while(currentScope->i16Variable != NULL) {
        I16Variable* tempVar = currentScope->i16Variable;
        currentScope->i16Variable = tempVar->next;
        free(tempVar);
    }
}

void freeI32Variables() {
    while(currentScope->i16Variable != NULL) {
        I32Variable* tempVar = currentScope->i32Variable;
        currentScope->i32Variable = tempVar->next;
        free(tempVar);
    }
}

void freeI64Variables() {
    while(currentScope->i64Variable != NULL) {
        I64Variable* tempVar = currentScope->i64Variable;
        currentScope->i64Variable = tempVar->next;
        free(tempVar);
    }
}

void freeI128Variables() {
    while(currentScope->i128Variable != NULL) {
        I128Variable* tempVar = currentScope->i128Variable;
        currentScope->i128Variable = tempVar->next;
        free(tempVar);
    }
}

void freeU8Variables() {
    while(currentScope->u8Variable != NULL) {
        U8Variable* tempVar = currentScope->u8Variable;
        currentScope->u8Variable = tempVar->next;
        free(tempVar);
    }
}

void freeU16Variables() {
    while(currentScope->u16Variable != NULL) {
        U16Variable* tempVar = currentScope->u16Variable;
        currentScope->u16Variable = tempVar->next;
        free(tempVar);
    }
}

void freeU32Variables() {
    while(currentScope->u32Variable != NULL) {
        U32Variable* tempVar = currentScope->u32Variable;
        currentScope->u32Variable = tempVar->next;
        free(tempVar);
    }
}

void freeU64Variables() {
    while(currentScope->u64Variable != NULL) {
        U64Variable* tempVar = currentScope->u64Variable;
        currentScope->u64Variable = tempVar->next;
        free(tempVar);
    }
}

void freeU128Variables() {
    while(currentScope->i128Variable != NULL) {
        I128Variable* tempVar = currentScope->i128Variable;
        currentScope->i128Variable = tempVar->next;
        free(tempVar);
    }
}

void freeF32Variables() {
    while(currentScope->f32Variable != NULL) {
        F32Variable* tempVar = currentScope->f32Variable;
        currentScope->f32Variable = tempVar->next;
        free(tempVar);
    }
}

void freeF64Variables() {
    while(currentScope->f64Variable != NULL) {
        F64Variable* tempVar = currentScope->f64Variable;
        currentScope->f64Variable = tempVar->next;
        free(tempVar);
    }
}

void freeBoolVariables() {
    while(currentScope->boolVariable != NULL) {
        BoolVariable* tempVar = currentScope->boolVariable;
        currentScope->boolVariable = tempVar->next;
        free(tempVar);
    }
}

void freeStringVariables() {
    while(currentScope->stringVariable != NULL) {
        StringVariable* tempVar = currentScope->stringVariable;
        currentScope->stringVariable = tempVar->next;
        free(tempVar->value);
        free(tempVar);
    }
}