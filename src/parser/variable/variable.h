/**
 The Kipl Programming Language

 File: parser/variable/variable.h

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#ifndef VARIABLE_H
#define VARIABLE_H

#include "../dataType.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum _var_type {
    VAR_TYPE_VAR,
    VAR_TYPE_CONST
} VarType;

typedef struct _i8_variable {
    char* name;
    int8_t value;
    int8_t* address;
    bool isMutable;
    VarType type;
    struct _i8_variable* next;
} I8Variable;

typedef struct _i16_variable {
    char* name;
    int16_t value;
    int16_t* address;
    bool isMutable;
    VarType type;
    struct _i16_variable* next;
} I16Variable;

typedef struct _i32_variable {
    char* name;
    int32_t value;
    int32_t* address;
    bool isMutable;
    VarType type;
    struct _i32_variable* next;
} I32Variable;

typedef struct _i64_variable {
    char* name;
    int64_t value;
    int64_t* address;
    bool isMutable;
    VarType type;
    struct _i64_variable* next;
} I64Variable;

typedef struct _i128_variable {
    char* name;
    __int128_t value;
    __int128_t* address;
    bool isMutable;
    VarType type;
    struct _i128_variable* next;
} I128Variable;

typedef struct _u8_variable {
    char* name;
    uint8_t value;
    uint8_t* address;
    bool isMutable;
    VarType type;
    struct _u8_variable* next;
} U8Variable;

typedef struct _u16_variable {
    char* name;
    uint16_t value;
    uint16_t* address;
    bool isMutable;
    VarType type;
    struct _u16_variable* next;
} U16Variable;

typedef struct _u32_variable {
    char* name;
    uint32_t value;
    uint32_t* address;
    bool isMutable;
    VarType type;
    struct _u32_variable* next;
} U32Variable;

typedef struct _u64_variable {
    char* name;
    uint64_t value;
    uint64_t* address;
    bool isMutable;
    VarType type;
    struct _u64_variable* next;
} U64Variable;

typedef struct _u128_variable {
    char* name;
    __uint128_t value;
    __uint128_t* address;
    bool isMutable;
    VarType type;
    struct _u128_variable* next;
} U128Variable;

typedef struct _f32_variable {
    char* name;
    float value;
    float* address;
    bool isMutable;
    VarType type;
    struct _f32_variable* next;
} F32Variable;

typedef struct _f64_variable {
    char* name;
    double value;
    double* address;
    bool isMutable;
    VarType type;
    struct _f64_variable* next;
} F64Variable;

typedef struct _bool_variable {
    char* name;
    bool value;
    bool* address;
    bool isMutable;
    VarType type;
    struct _bool_variable* next;
} BoolVariable;

typedef struct _string_variable {
    char* name;
    char* value;
    char** address;
    bool isMutable;
    VarType type;
    struct _string_variable* next;
} StringVariable;

void createVariable(DataType type, char* name, VarType varType);

void createI8Variable(char* name, VarType varType);

void createI16Variable(char* name, VarType varType);

void createI32Variable(char* name, VarType varType);

void createI64Variable(char* name, VarType varType);

void createI128Variable(char* name, VarType varType);

void createU8Variable(char* name, VarType varType);

void createU16Variable(char* name, VarType varType);

void createU32Variable(char* name, VarType varType);

void createU64Variable(char* name, VarType varType);

void createU128Variable(char* name, VarType varType);

void createF32Variable(char* name, VarType varType);

void createF64Variable(char* name, VarType varType);

void createBoolVariable(char* name, VarType varType);

void createStringVariable(char* name, VarType varType);


#endif //VARIABLE_H
