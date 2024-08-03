//
// Created by Kerem on 31/07/2024.
//

#ifndef VARIABLE_H
#define VARIABLE_H

#include <stdint.h>
#include <stdbool.h>

typedef enum _data_type {
    TYPE_I8,
    TYPE_I16,
    TYPE_I32,
    TYPE_I64,
    TYPE_I128,
    TYPE_U8,
    TYPE_U16,
    TYPE_U32,
    TYPE_U64,
    TYPE_U128,
    TYPE_F32,
    TYPE_F64,
    TYPE_BOOL,
    TYPE_STRING
} DataType;

void createVariable(DataType type, char* name, char* value);

typedef struct _i8_variable {
    char* name;
    int8_t value;
    int8_t* address;
    struct _i8_variable* next;
} I8Variable;

typedef struct _i16_variable {
    char* name;
    int16_t value;
    int16_t* address;
    struct _i16_variable* next;
} I16Variable;

typedef struct _i32_variable {
    char* name;
    int32_t value;
    int32_t* address;
    struct _i32_variable* next;
} I32Variable;

typedef struct _i64_variable {
    char* name;
    int64_t value;
    int64_t* address;
    struct _i64_variable* next;
} I64Variable;

typedef struct _i128_variable {
    char* name;
    __int128_t value;
    __int128_t* address;
    struct _i128_variable* next;
} I128Variable;

typedef struct _u8_variable {
    char* name;
    uint8_t value;
    uint8_t* address;
    struct _u8_variable* next;
} U8Variable;

typedef struct _u16_variable {
    char* name;
    uint16_t value;
    uint16_t* address;
    struct _u16_variable* next;
} U16Variable;

typedef struct _u32_variable {
    char* name;
    uint32_t value;
    uint32_t* address;
    struct _u32_variable* next;
} U32Variable;

typedef struct _u64_variable {
    char* name;
    uint64_t value;
    uint64_t* address;
    struct _u64_variable* next;
} U64Variable;

typedef struct _u128_variable {
    char* name;
    __uint128_t value;
    __uint128_t* address;
    struct _u128_variable* next;
} U128Variable;

typedef struct _f32_variable {
    char* name;
    float value;
    float* address;
    struct _f32_variable* next;
} F32Variable;

typedef struct _f64_variable {
    char* name;
    double value;
    double* address;
    struct _f64_variable* next;
} F64Variable;

typedef struct _bool_variable {
    char* name;
    bool value;
    bool* address;
    struct _bool_variable* next;
} BoolVariable;

typedef struct _string_variable {
    char* name;
    char* value;
    char** address;
    struct _string_variable* next;
} StringVariable;

void createI8Variable(char* name, int8_t value);

void createI16Variable(int16_t value);

void createI32Variable(int32_t value);

void createI64Variable(int64_t value);

void createI128Variable(__int128_t value);

void createU8Variable(uint8_t value);

void createU16Variable(uint16_t value);

void createU32Variable(uint32_t value);

void creatU64Variable(uint64_t value);

void createU128Variable(__uint128_t value);

void createF32Variable(float value);

void createF64Variable(double value);

void createBoolVariable(bool value);

void createStringVariable(char* value);


#endif //VARIABLE_H
