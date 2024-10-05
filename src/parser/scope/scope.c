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

#include <stdio.h>

#include "../global.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../error/error.h"
#include "../helpers/typeConversion/toBool.h"


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

bool isVariableInCurrentScope(const char* name, Scope* scope) {
    I8Variable* tempI8Var = scope->i8Variable;
    while(tempI8Var != NULL) {
        if(!strcmp(name, tempI8Var->name))
            return true;
        tempI8Var = tempI8Var->next;
    }

    I16Variable* tempI16Var = scope->i16Variable;
    while(tempI16Var != NULL) {
        if(!strcmp(name, tempI16Var->name))
            return true;
        tempI16Var = tempI16Var->next;
    }

    I32Variable* tempI32Var = scope->i32Variable;
    while(tempI32Var != NULL) {
        if(!strcmp(name, tempI32Var->name))
            return true;
        tempI32Var = tempI32Var->next;
    }

    I64Variable* tempI64Var = scope->i64Variable;
    while(tempI64Var != NULL) {
        if(!strcmp(name, tempI64Var->name))
            return true;
        tempI64Var = tempI64Var->next;
    }

    I128Variable* tempI128Var = scope->i128Variable;
    while(tempI128Var != NULL) {
        if(!strcmp(name, tempI128Var->name))
            return true;
        tempI128Var = tempI128Var->next;
    }

    U8Variable* tempU8Var = scope->u8Variable;
    while(tempU8Var != NULL) {
        if(!strcmp(name, tempU8Var->name))
            return true;
        tempU8Var = tempU8Var->next;
    }

    U16Variable* tempU16Var = scope->u16Variable;
    while(tempU16Var != NULL) {
        if(!strcmp(name, tempU16Var->name))
            return true;
        tempU16Var = tempU16Var->next;
    }

    U32Variable* tempU32Var = scope->u32Variable;
    while(tempU32Var != NULL) {
        if(!strcmp(name, tempU32Var->name))
            return true;
        tempU32Var = tempU32Var->next;
    }

    U64Variable* tempU64Var = scope->u64Variable;
    while(tempU64Var != NULL) {
        if(!strcmp(name, tempU64Var->name))
            return true;
        tempU64Var = tempU64Var->next;
    }

    U128Variable* tempU128Var = scope->u128Variable;
    while(tempU128Var != NULL) {
        if(!strcmp(name, tempU128Var->name))
            return true;
        tempU128Var = tempU128Var->next;
    }

    F32Variable* tempF32Var = scope->f32Variable;
    while(tempF32Var != NULL) {
        if(!strcmp(name, tempF32Var->name))
            return true;
        tempF32Var = tempF32Var->next;
    }

    F64Variable* tempF64Var = scope->f64Variable;
    while(tempF64Var != NULL) {
        if(!strcmp(name, tempF64Var->name))
            return true;
        tempF64Var = tempF64Var->next;
    }

    BoolVariable* tempBoolVar = scope->boolVariable;
    while(tempBoolVar != NULL) {
        if(!strcmp(name, tempBoolVar->name))
            return true;
        tempBoolVar = tempBoolVar->next;
    }

    StringVariable* tempStringVar = scope->stringVariable;
    while(tempStringVar != NULL) {
        if(!strcmp(name, tempStringVar->name))
            return true;
        tempStringVar = tempStringVar->next;
    }

    return false;
}


bool isVariableInAllScope(const char* name) {
    Scope* tempScope = currentScope;

    while(tempScope != NULL) {
        if(isVariableInCurrentScope(name, tempScope))
            return true;

        tempScope = tempScope->parentScope;
    }
    return false;
}

/*
 *
 */
void assignToVariable(const char* varName, Data* data) {
    Scope* tempScope = currentScope;

    while(tempScope != NULL) {

        I8Variable* tempI8Var = tempScope->i8Variable;
        while(tempI8Var != NULL) {
            if(!strcmp(varName, tempI8Var->name)) {
                tempI8Var->isMutable = mutableControl(tempI8Var->type, tempI8Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    int8_t dataValue = (int8_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempI8Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempI8Var = tempI8Var->next;
        }

        I16Variable* tempI16Var = tempScope->i16Variable;
        while(tempI16Var != NULL) {
            if(!strcmp(varName, tempI16Var->name)) {
                tempI16Var->isMutable = mutableControl(tempI16Var->type, tempI16Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    int16_t dataValue = (int16_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempI16Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempI16Var = tempI16Var->next;
        }

        I32Variable* tempI32Var = tempScope->i32Variable;
        while(tempI32Var != NULL) {
            if(!strcmp(varName, tempI32Var->name)) {
                tempI32Var->isMutable = mutableControl(tempI32Var->type, tempI32Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    int32_t dataValue = (int32_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempI32Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempI32Var = tempI32Var->next;
        }

        I64Variable* tempI64Var = tempScope->i64Variable;
        while(tempI64Var != NULL) {
            if(!strcmp(varName, tempI64Var->name)) {
                tempI64Var->isMutable = mutableControl(tempI64Var->type, tempI64Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    int64_t dataValue = (int64_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempI64Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempI64Var = tempI64Var->next;
        }

        I128Variable* tempI128Var = tempScope->i128Variable;
        while(tempI128Var != NULL) {
            if(!strcmp(varName, tempI128Var->name)) {
                tempI128Var->isMutable = mutableControl(tempI128Var->type, tempI128Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    __int128_t dataValue = (__int128_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempI128Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempI128Var = tempI128Var->next;
        }

        U8Variable* tempU8Var = tempScope->u8Variable;
        while(tempU8Var != NULL) {
            if(!strcmp(varName, tempU8Var->name)) {
                tempU8Var->isMutable = mutableControl(tempU8Var->type, tempU8Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    uint8_t dataValue = (uint8_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value rang
                        tempU8Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempU8Var = tempU8Var->next;
        }

        U16Variable* tempU16Var = tempScope->u16Variable;
        while(tempU16Var != NULL) {
            if(!strcmp(varName, tempU16Var->name)) {
                tempU16Var->isMutable = mutableControl(tempU16Var->type, tempU16Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    uint16_t dataValue = (uint16_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempU16Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempU16Var = tempU16Var->next;
        }

        U32Variable* tempU32Var = tempScope->u32Variable;
        while(tempU32Var != NULL) {
            if(!strcmp(varName, tempU32Var->name)) {
                tempU32Var->isMutable = mutableControl(tempU32Var->type, tempU32Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    uint32_t dataValue = (uint32_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempU32Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempU32Var = tempU32Var->next;
        }

        U64Variable* tempU64Var = tempScope->u64Variable;
        while(tempU64Var != NULL) {
            if(!strcmp(varName, tempU64Var->name)) {
                tempU64Var->isMutable = mutableControl(tempU64Var->type, tempU64Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    uint64_t dataValue = (uint64_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempU64Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempU64Var = tempU64Var->next;
        }

        U128Variable* tempU128Var = tempScope->u128Variable;
        while(tempU128Var != NULL) {
            if(!strcmp(varName, tempU128Var->name)) {
                tempU128Var->isMutable = mutableControl(tempU128Var->type, tempU128Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    __uint128_t dataValue = (__uint128_t) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        // is integer and is correct value range
                        tempU128Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempU128Var = tempU128Var->next;
        }


        F32Variable* tempF32Var = tempScope->f32Variable;
        while(tempF32Var != NULL) {
            if(!strcmp(varName, tempF32Var->name)) {
                tempF32Var->isMutable = mutableControl(tempF32Var->type, tempF32Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    float dataValue = (float) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        tempF32Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempF32Var = tempF32Var->next;
        }

        F64Variable* tempF64Var = tempScope->f64Variable;
        while(tempF64Var != NULL) {
            if(!strcmp(varName, tempF64Var->name)) {
                tempF64Var->isMutable = mutableControl(tempF64Var->type, tempF64Var->isMutable);
                if(dataTypeIsNumber(data->dataType)) {
                    double dataValue = (double) atof(data->value);
                    if(atof(data->value) == dataValue) {
                        tempF64Var->value = dataValue;
                        freeData(data);
                        return;
                    }
                    showError(ERROR_RUNTIME, "invalid value range");
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a number", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempF64Var = tempF64Var->next;
        }

        BoolVariable* tempBoolVar = tempScope->boolVariable;
        while(tempBoolVar != NULL) {
            if(!strcmp(varName, tempBoolVar->name)) {
                tempBoolVar->isMutable = mutableControl(tempBoolVar->type, tempBoolVar->isMutable);
                if(data->dataType == TYPE_BOOL) {
                    tempBoolVar->value = stringToBool(data->value);
                    freeData(data);
                    return;
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a boolean expression", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempBoolVar = tempBoolVar->next;
        }

        StringVariable* tempStringVar = tempScope->stringVariable;
        while(tempStringVar != NULL) {
            if(!strcmp(varName, tempStringVar->name)) {
                tempStringVar->isMutable = mutableControl(tempStringVar->type, tempStringVar->isMutable);
                if(data->dataType == TYPE_STRING) {
                    free(tempStringVar->value);
                    tempStringVar->value = strdup(data->value);
                    freeData(data);
                    return;
                }

                char* errMsg[50];
                sprintf(errMsg, "%s is not a string", data->value);
                showError(ERROR_RUNTIME, errMsg);
            }
            tempStringVar = tempStringVar->next;
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

bool mutableControl(VarType varType, bool isMutable) {
    if(isMutable) {
        if(varType == VAR_TYPE_VAR)
            return true;
        if(varType == VAR_TYPE_CONST)
            return false;
    }

    showError(ERROR_SYNTAX, "The variable is unmutable");
    return false; // oylesine
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