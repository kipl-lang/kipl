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
#include <string.h>


void createScope() {
    Scope* scope = (Scope*) malloc(sizeof(Scope)); // New Scope
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

bool isVariableInCurrentScope(const char* name) {
    I8Variable* tempI8Var = currentScope->i8Variable;
    while(tempI8Var != NULL) {
        if(!strcmp(name, tempI8Var->name))
            return true;
        tempI8Var = tempI8Var->next;
    }

    I16Variable* tempI16Var = currentScope->i16Variable;
    while(tempI16Var != NULL) {
        if(!strcmp(name, tempI16Var->name))
            return true;
        tempI16Var = tempI16Var->next;
    }

    I32Variable* tempI32Var = currentScope->i32Variable;
    while(tempI32Var != NULL) {
        if(!strcmp(name, tempI32Var->name))
            return true;
        tempI32Var = tempI32Var->next;
    }

    I64Variable* tempI64Var = currentScope->i64Variable;
    while(tempI64Var != NULL) {
        if(!strcmp(name, tempI64Var->name))
            return true;
        tempI64Var = tempI64Var->next;
    }

    I128Variable* tempI128Var = currentScope->i128Variable;
    while(tempI128Var != NULL) {
        if(!strcmp(name, tempI128Var->name))
            return true;
        tempI128Var = tempI128Var->next;
    }

    U8Variable* tempU8Var = currentScope->u8Variable;
    while(tempU8Var != NULL) {
        if(!strcmp(name, tempU8Var->name))
            return true;
        tempU8Var = tempU8Var->next;
    }

    U16Variable* tempU16Var = currentScope->u16Variable;
    while(tempU16Var != NULL) {
        if(!strcmp(name, tempU16Var->name))
            return true;
        tempU16Var = tempU16Var->next;
    }

    U32Variable* tempU32Var = currentScope->u32Variable;
    while(tempU32Var != NULL) {
        if(!strcmp(name, tempU32Var->name))
            return true;
        tempU32Var = tempU32Var->next;
    }

    U64Variable* tempU64Var = currentScope->u64Variable;
    while(tempU64Var != NULL) {
        if(!strcmp(name, tempU64Var->name))
            return true;
        tempU64Var = tempU64Var->next;
    }

    U128Variable* tempU128Var = currentScope->u128Variable;
    while(tempU128Var != NULL) {
        if(!strcmp(name, tempU128Var->name))
            return true;
        tempU128Var = tempU128Var->next;
    }

    F32Variable* tempF32Var = currentScope->f32Variable;
    while(tempF32Var != NULL) {
        if(!strcmp(name, tempF32Var->name))
            return true;
        tempF32Var = tempF32Var->next;
    }

    F64Variable* tempF64Var = currentScope->f64Variable;
    while(tempF64Var != NULL) {
        if(!strcmp(name, tempF64Var->name))
            return true;
        tempF64Var = tempF64Var->next;
    }

    BoolVariable* tempBoolVar = currentScope->boolVariable;
    while(tempBoolVar != NULL) {
        if(!strcmp(name, tempBoolVar->name))
            return true;
        tempBoolVar = tempBoolVar->next;
    }

    StringVariable* tempStringVar = currentScope->stringVariable;
    while(tempStringVar != NULL) {
        if(!strcmp(name, tempStringVar->name))
            return true;
        tempStringVar = tempStringVar->next;
    }

    return false;
}


//henüz kullanılmıyor belki ileride kullanrıım.
bool isVariableInAllScope(const char* name) {
    Scope* tempScope = currentScope;

    while(tempScope != NULL) {
        if(isVariableInCurrentScope(name))
            return true;

        tempScope = tempScope->parentScope;
    }
    return false;
}

void assignToVariable(const char* varName, Data* data) {
    Scope* tempScope = currentScope;

    while(tempScope != NULL) {

        I8Variable* tempI8Var = currentScope->i8Variable;
        while(tempI8Var != NULL) {
            if(!strcmp(varName, tempI8Var->name))
                if()
            tempI8Var = tempI8Var->next;
        }

        tempScope = tempScope->parentScope;
    }


}

bool dataTypeIsNumber(DataType type) {
    switch(type) {
        case TYPE_I8:
        case TYPE_I16:
        case TYPE_I32:
        case TYPE_I64:
        case TYPE_I128:
        case TYPE_U8:
        case TYPE_U16:
        case TYPE_U32:
        case TYPE_U64:
        case TYPE_U128:
        case TYPE_F32:
        case TYPE_F64:
            return true;
        default:
            return false;
    }
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