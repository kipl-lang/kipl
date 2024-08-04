/**
 The Kipl Programming Language

 File: parser/helpers/dataTypes/getDataType.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include "getDataType.h"

DataType getDataType(TokenType type) {
    switch(type) {
        case TOKEN_TYPE_I8:
            return TYPE_I8;
        case TOKEN_TYPE_I16:
            return TYPE_I16;
        case TOKEN_TYPE_I32:
            return TYPE_I32;
        case TOKEN_TYPE_I64:
            return TYPE_I64;
        case TOKEN_TYPE_I128:
            return TYPE_I128;
        case TOKEN_TYPE_U8:
            return TYPE_U8;
        case TOKEN_TYPE_U16:
            return TYPE_U16;
        case TOKEN_TYPE_U32:
            return TYPE_U32;
        case TOKEN_TYPE_U64:
            return TYPE_U64;
        case TOKEN_TYPE_U128:
            return TYPE_U128;
        case TOKEN_TYPE_F32:
            return TYPE_F32;
        case TOKEN_TYPE_F64:
            return TYPE_F64;
        case TOKEN_TYPE_BOOL:
            return TYPE_BOOL;
        case TOKEN_TYPE_STRING:
            return TYPE_STRING;
        default:
            return TYPE_VOID;
    }
}