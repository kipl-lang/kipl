//
// Created by Kerem on 31/07/2024.
//

#include "variable.h"

#include <stdlib.h>

#include "../global.h"
#include "../error/error.h"

void createVariable(DataType type, char* value) {
    switch(type) {
        case TYPE_I8:
            break;
        case TYPE_I16:
            break;
        case TYPE_I32:
            break;
        case TYPE_I64:
            break;
        case TYPE_I128:
            break;
        case TYPE_U8:
            break;
        case TYPE_U16:
            break;
        case TYPE_U32:
            break;
        case TYPE_U64:
            break;
        case TYPE_U128:
            break;
        case TYPE_F32:
            break;
        case TYPE_F64:
            break;
        case TYPE_BOOL:
            break;
        case TYPE_STRING:
            break;
        default:
            showError(ERROR_RUNTIME, "unkown error");
    }
}

void createI8Variable(char* value) {
    I8Variable* variable = (I8Variable*) malloc(sizeof(I8Variable));
    variable->value = atoi();
}