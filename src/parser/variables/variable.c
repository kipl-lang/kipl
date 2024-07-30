//
// Created by Kerem on 29/07/2024.
//

#include "variable.h"
#include "stdlib.h"

Variable* createVariable(VariableType type, char* name, char* value) {
    Variable* variable = (Variable*) malloc(sizeof(Variable));
    variable->type = type;
    variable->name = name;

    switch (type) {
        case TYPE_I8:
            variable->value.i8 = atoi(value);
        case TYPE_I16:
            variable->value.i16 = atoi(value);
        case TYPE_I32:
            variable->value.i32 = atoi(value);
        case TYPE_I64:
            variable->value.i64 =_atoi64(value);
        case TYPE_I128:
            variable->value.i128 = atoi(value);
        case TYPE_U8:
            variable->value.u8 =
        case TYPE_U16:
        case TYPE_U32:
        case TYPE_U64:
        case TYPE_U128:
        case TYPE_F32:
        case TYPE_F64:
            return
        case
            return 1;
}

size_t getVariableSize(VariableType type) {
    switch (type) {
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
            return
        case
            return 1;
    }
}