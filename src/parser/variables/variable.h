//
// Created by Kerem on 29/07/2024.
//

#ifndef VARIABLE_H
#define VARIABLE_H

#include "stdint.h"
#include "stdbool.h"

typedef enum _variable_type {
    TYPE_I8,        // 1  BYTE
    TYPE_I16,       // 2  BYTE
    TYPE_I32,       // 4  BYTE
    TYPE_I64,       // 8  BYTE
    TYPE_I128,      // 16 BYTE
    TYPE_U8,        // 1  BYTE
    TYPE_U16,       // 2  BYTE
    TYPE_U32,       // 4  BYTE
    TYPE_U64,       // 8  BYTE
    TYPE_U128,      // 16 BYTE
    TYPE_F32,       // 4  BYTE
    TYPE_F64,       // 8  BYTE
    TYPE_STRING,
    TYPE_BOOL       // 1  BIT
} VariableType;

typedef union _variable_value {
    int8_t i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;
    __int128_t i128;
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    uint64_t u64;
    __uint128_t u128;
    float f32;
    double f64;
    char* string;
    bool b;
} VariableValue;

typedef struct _variable {
    VariableType type;
    char* name;
    VariableValue value;
} Variable;

Variable* createVariable(VariableType type, char* name, char* value);


size_t getVariableSize(VariableType type);



#endif //VARIABLE_H
