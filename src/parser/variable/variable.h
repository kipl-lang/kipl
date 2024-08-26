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

typedef struct _i8_variable {
    char* name;
    int8_t value;
    int8_t* address;
    bool isMutable;
    struct _i8_variable* next;
} I8Variable;

typedef struct _i16_variable {
    char* name;
    int16_t value;
    int16_t* address;
    bool isMutable;
    struct _i16_variable* next;
} I16Variable;

typedef struct _i32_variable {
    char* name;
    int32_t value;
    int32_t* address;
    bool isMutable;
    struct _i32_variable* next;
} I32Variable;

typedef struct _i64_variable {
    char* name;
    int64_t value;
    int64_t* address;
    bool isMutable;
    struct _i64_variable* next;
} I64Variable;

typedef struct _i128_variable {
    char* name;
    __int128_t value;
    __int128_t* address;
    bool isMutable;
    struct _i128_variable* next;
} I128Variable;

typedef struct _u8_variable {
    char* name;
    uint8_t value;
    uint8_t* address;
    bool isMutable;
    struct _u8_variable* next;
} U8Variable;

typedef struct _u16_variable {
    char* name;
    uint16_t value;
    uint16_t* address;
    bool isMutable;
    struct _u16_variable* next;
} U16Variable;

typedef struct _u32_variable {
    char* name;
    uint32_t value;
    uint32_t* address;
    bool isMutable;
    struct _u32_variable* next;
} U32Variable;

typedef struct _u64_variable {
    char* name;
    uint64_t value;
    uint64_t* address;
    bool isMutable;
    struct _u64_variable* next;
} U64Variable;

typedef struct _u128_variable {
    char* name;
    __uint128_t value;
    __uint128_t* address;
    bool isMutable;
    struct _u128_variable* next;
} U128Variable;

typedef struct _f32_variable {
    char* name;
    float value;
    float* address;
    bool isMutable;
    struct _f32_variable* next;
} F32Variable;

typedef struct _f64_variable {
    char* name;
    double value;
    double* address;
    bool isMutable;
    struct _f64_variable* next;
} F64Variable;

typedef struct _bool_variable {
    char* name;
    bool value;
    bool* address;
    bool isMutable;
    struct _bool_variable* next;
} BoolVariable;

typedef struct _string_variable {
    char* name;
    char* value;
    char** address;
    bool isMutable;
    struct _string_variable* next;
} StringVariable;

void createVariable(DataType type, char* name);

void createI8Variable(char* name);

void createI16Variable(char* name);

void createI32Variable(char* name);

void createI64Variable(char* name);

void createI128Variable(char* name);

void createU8Variable(char* name);

void createU16Variable(char* name);

void createU32Variable(char* name);

void createU64Variable(char* name);

void createU128Variable(char* name);

void createF32Variable(char* name);

void createF64Variable(char* name);

void createBoolVariable(char* name);

void createStringVariable(char* name);


#endif //VARIABLE_H
