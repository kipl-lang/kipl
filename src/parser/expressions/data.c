//
// Created by Kerem on 04/08/2024.
//

#include "data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../global.h"
#include "../helpers/typeConversion/typeConversion.h"
#include "../variable/variable.h"


Data* createData(DataType dataType, char* value) {
    Data* data = (Data*) malloc(sizeof(Data)); // new data;
    data->dataType = dataType;
    data->value = value;
    return data;
}

Data* getDataFromVariable(char* name) {
    Scope* tempScope = currentScope;

    while(tempScope != NULL) {

        I8Variable* tempI8Variable = tempScope->i8Variable;
        while(tempI8Variable != NULL) {
            if(!strcmp(name, tempI8Variable->name)) {
                char* str = int8_tToString(tempI8Variable->value);
                return createData(TYPE_I8, str);
            }
            tempI8Variable = tempI8Variable->next;
        }

        I16Variable* tempI16Variable = tempScope->i16Variable;
        while(tempI16Variable != NULL) {
            if(!strcmp(name, tempI16Variable->name)) {
                char* str = int16_tToString(tempI16Variable->value);
                return createData(TYPE_I16, str);
            }
            tempI16Variable = tempI16Variable->next;
        }

        I32Variable* tempI32Variable = tempScope->i32Variable;
        while(tempI32Variable != NULL) {
            if(!strcmp(name, tempI32Variable->name)) {
                char* str = int32_tToString(tempI32Variable->value);
                return createData(TYPE_I32, str);
            }
            tempI32Variable = tempI32Variable->next;
        }

        I64Variable* tempI64Variable = tempScope->i64Variable;
        while(tempI64Variable != NULL) {
            if(!strcmp(name, tempI64Variable->name)) {
                char* str = int64_tToString(tempI64Variable->value);
                return createData(TYPE_I64, str);
            }
            tempI64Variable = tempI64Variable->next;
        }

        I128Variable* tempI128Variable = tempScope->i128Variable;
        while(tempI128Variable != NULL) {
            if(!strcmp(name, tempI128Variable->name)) {
                char* str = __int128_tToString(tempI128Variable->value);
                return createData(TYPE_I128, str);
            }
            tempI128Variable = tempI128Variable->next;
        }

        U8Variable* tempU8Variable = tempScope->u8Variable;
        while(tempU8Variable != NULL) {
            if(!strcmp(name, tempU8Variable->name)) {
                char* str = uint8_tToString(tempU8Variable->value);
                return createData(TYPE_U8, str);
            }
            tempU8Variable = tempU8Variable->next;
        }

        U16Variable* tempU16Variable = tempScope->u16Variable;
        while(tempU16Variable != NULL) {
            if(!strcmp(name, tempU16Variable->name)) {
                char* str = uint16_tToString(tempU16Variable->value);
                return createData(TYPE_U16, str);
            }
            tempU16Variable = tempU16Variable->next;
        }

        U32Variable* tempU32Variable = tempScope->u32Variable;
        while(tempU32Variable != NULL) {
            if(!strcmp(name, tempU32Variable->name)) {
                char* str = uint32_tToString(tempU32Variable->value);
                return createData(TYPE_U32, str);
            }
            tempU32Variable = tempU32Variable->next;
        }

        U64Variable* tempU64Variable = tempScope->u64Variable;
        while(tempU64Variable != NULL) {
            if(!strcmp(name, tempU64Variable->name)) {
                char* str = uint64_tToString(tempU64Variable->value);
                return createData(TYPE_U64, str);
            }
            tempU64Variable = tempU64Variable->next;
        }

        U128Variable* tempU128Variable = tempScope->u128Variable;
        while(tempU128Variable != NULL) {
            if(!strcmp(name, tempU128Variable->name)) {
                char* str = __uint128_tToString(tempU128Variable->value);
                return createData(TYPE_I128, str);
            }
            tempU128Variable = tempU128Variable->next;
        }

        F32Variable* tempF32Variable = tempScope->f32Variable;
        while(tempF32Variable != NULL) {
            if(!strcmp(name, tempF32Variable->name)) {
                char* str = floatToString(tempF32Variable->value);
                return createData(TYPE_F32, str);
            }
            tempF32Variable = tempF32Variable->next;
        }

        F64Variable* tempF64Variable = tempScope->f64Variable;
        while(tempF64Variable != NULL) {
            if(!strcmp(name, tempF64Variable->name)) {
                char* str = doubleToString(tempF64Variable->value);
                return createData(TYPE_F64, str);
            }
            tempF64Variable = tempF64Variable->next;
        }

        BoolVariable* tempBoolVariable = tempScope->boolVariable;
        while(tempBoolVariable != NULL) {
            if(!strcmp(name, tempBoolVariable->name)) {
                char* str = boolToString(tempBoolVariable->value);
                return createData(TYPE_BOOL, str);
            }
            tempBoolVariable = tempBoolVariable->next;
        }

        StringVariable* tempStringVariable = tempScope->stringVariable;
        while(tempStringVariable != NULL) {
            if(!strcmp(name, tempStringVariable->name)) {
                return createData(TYPE_STRING, strdup(tempStringVariable->value));
            }
            tempStringVariable = tempStringVariable->next;
        }

        tempScope = tempScope->parentScope;
    }

    return NULL; // variable undefined
}

void freeData(Data* data) {
    free(data->value);
    free(data);
}