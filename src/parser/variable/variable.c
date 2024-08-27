/**
 The Kipl Programming Language

 File: parser/variable/variable.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/


#include "variable.h"

#include <stdlib.h>
#include <string.h>

#include "../global.h"
#include "../error/error.h"

void createVariable(DataType type, char* name, VarType varType) {
    switch(type) {
        case TYPE_I8:
            createI8Variable(name, varType);
            break;
        case TYPE_I16:
            createI16Variable(name, varType);
            break;
        case TYPE_I32:
            createI32Variable(name, varType);
            break;
        case TYPE_I64:
            createI64Variable(name, varType);
            break;
        case TYPE_I128:
            createI128Variable(name, varType);
            break;
        case TYPE_U8:
            createU8Variable(name, varType);
            break;
        case TYPE_U16:
            createU16Variable(name, varType);
            break;
        case TYPE_U32:
            createU32Variable(name, varType);
            break;
        case TYPE_U64:
            createU64Variable(name, varType);
            break;
        case TYPE_U128:
            createU128Variable(name, varType);
            break;
        case TYPE_F32:
            createF32Variable(name, varType);
            break;
        case TYPE_F64:
            createF64Variable(name, varType);
            break;
        case TYPE_BOOL:
            createBoolVariable(name, varType);
            break;
        case TYPE_STRING:
            createStringVariable(name, varType);
            break;
        default:
            showError(ERROR_RUNTIME, "unkown error");
    }
}

void createI8Variable(char* name, VarType varType) {
    I8Variable* variable = (I8Variable*) malloc(sizeof(I8Variable)); // new variable
    variable->name = name;
    variable->value = (int8_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->i8Variable == NULL)
        currentScope->i8Variable = variable;
    else {
        I8Variable* tempVar = currentScope->i8Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createI16Variable(char* name, VarType varType) {
    I16Variable* variable = (I16Variable*) malloc(sizeof(I16Variable));
    variable->name = name;
    variable->value = (int16_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->i16Variable == NULL)
        currentScope->i16Variable = variable;
    else {
        I16Variable* tempVar = currentScope->i16Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createI32Variable(char* name, VarType varType) {
    I32Variable* variable = (I32Variable*) malloc(sizeof(I32Variable));
    variable->name = name;
    variable->value = (int32_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->i32Variable == NULL)
        currentScope->i32Variable = variable;
    else {
        I32Variable* tempVar = currentScope->i32Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createI64Variable(char* name, VarType varType) {
    I64Variable* variable = (I64Variable*) malloc(sizeof(I64Variable));
    variable->name = name;
    variable->value = (int64_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->i64Variable == NULL)
        currentScope->i64Variable = variable;
    else {
        I64Variable* tempVar = currentScope->i64Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createI128Variable(char* name, VarType varType) {
    I128Variable* variable = (I128Variable*) malloc(sizeof(I128Variable));
    variable->name = name;
    variable->value = (__int128_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->i128Variable == NULL)
        currentScope->i128Variable = variable;
    else {
        I128Variable* tempVar = currentScope->i128Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createU8Variable(char* name, VarType varType) {
    U8Variable* variable = (U8Variable*) malloc(sizeof(U8Variable));
    variable->name = name;
    variable->value = (uint8_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->u8Variable == NULL)
        currentScope->u8Variable = variable;
    else {
        U8Variable* tempVar = currentScope->u8Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createU16Variable(char* name, VarType varType) {
    U16Variable* variable = (U16Variable*) malloc(sizeof(U16Variable));
    variable->name = name;
    variable->value = (uint16_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->u16Variable == NULL)
        currentScope->u16Variable = variable;
    else {
        U16Variable* tempVar = currentScope->u16Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createU32Variable(char* name, VarType varType) {
    U32Variable* variable = (U32Variable*) malloc(sizeof(U32Variable));
    variable->name = name;
    variable->value = (uint32_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->u32Variable == NULL)
        currentScope->u32Variable = variable;
    else {
        U32Variable* tempVar = currentScope->u32Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createU64Variable(char* name, VarType varType) {
    U64Variable* variable = (U64Variable*) malloc(sizeof(U64Variable));
    variable->name = name;
    variable->value = (uint64_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->u64Variable == NULL)
        currentScope->u64Variable = variable;
    else {
        U64Variable* tempVar = currentScope->u64Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createU128Variable(char* name, VarType varType) {
    U128Variable* variable = (U128Variable*) malloc(sizeof(U128Variable));
    variable->name = name;
    variable->value = (__uint128_t) 0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->u128Variable == NULL)
        currentScope->u128Variable = variable;
    else {
        U128Variable* tempVar = currentScope->u128Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createF32Variable(char* name, VarType varType) {
    F32Variable* variable = (F32Variable*) malloc(sizeof(F32Variable));
    variable->name = name;
    variable->value = (float) 0.0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->f32Variable == NULL)
        currentScope->f32Variable = variable;
    else {
        F32Variable* tempVar = currentScope->f32Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createF64Variable(char* name, VarType varType) {
    F64Variable* variable = (F64Variable*) malloc(sizeof(F64Variable));
    variable->name = name;
    variable->value = (double) 0.0;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->f64Variable == NULL)
        currentScope->f64Variable = variable;
    else {
        F64Variable* tempVar = currentScope->f64Variable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createBoolVariable(char* name, VarType varType) {
    BoolVariable* variable = (BoolVariable*) malloc(sizeof(BoolVariable));
    variable->name = name;
    variable->value = (bool) false;
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->boolVariable == NULL)
        currentScope->boolVariable = variable;
    else {
        BoolVariable* tempVar = currentScope->boolVariable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        }
        tempVar->next = variable;
    }
}

void createStringVariable(char* name, VarType varType) {
    StringVariable* variable = (StringVariable*) malloc(sizeof(StringVariable));
    variable->name = name;
    variable->value = strdup("");
    variable->address = &variable->value;
    variable->isMutable = true;
    variable->type = varType;
    variable->next = NULL;

    if(currentScope->stringVariable == NULL)
        currentScope->stringVariable = variable;
    else {
        StringVariable* tempVar = currentScope->stringVariable;
        while(tempVar->next != NULL) {
            tempVar = tempVar->next;
        } 
        tempVar->next = variable;
    }
}