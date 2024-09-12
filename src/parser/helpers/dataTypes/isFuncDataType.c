//
// Created by Kerem on 12/09/2024.
//

#include "isFuncDataType.h"

bool isDataType(TokenType type) {
    switch(type) {
        case TOKEN_TYPE_I8:
        case TOKEN_TYPE_I16:
        case TOKEN_TYPE_I32:
        case TOKEN_TYPE_I64:
        case TOKEN_TYPE_I128:
        case TOKEN_TYPE_U8:
        case TOKEN_TYPE_U16:
        case TOKEN_TYPE_U32:
        case TOKEN_TYPE_U64:
        case TOKEN_TYPE_U128:
        case TOKEN_TYPE_F32:
        case TOKEN_TYPE_F64:
        case TOKEN_TYPE_STRING:
        case TOKEN_TYPE_BOOL:
        case TOKEN_VOID:
            return true;
        default:
            return false;
    }
}
