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

typedef struct _variable {

} Variable;


typedef struct _i8_variable {
    int8_t value;
    int8_t* address;
} I8Variable;

typedef struct _i16_variable {
    int16_t value;
    int16_t* address;
} I16Variable;

typedef struct _i32_variable {
    int32_t value;
    int32_t* address;
} I32Variable;

typedef struct _i64_variable {
    int64_t value;
    int64_t* address;
} I64Variable;

typedef struct _i128_variable {
    __int128_t value;
    __int128_t* address;
} I128Variable;

typedef struct _u8_variable {
    uint8_t value;
    uint8_t* address;
} U8Variable;

typedef struct _u16_variable {
    uint16_t value;
    uint16_t* address;
} u16Variable;

typedef struct _u32_variable {
    uint32_t value;
    uint32_t* address;
} U32Variable;

typedef struct _u64_variable {
    uint64_t value;
    uint64_t* address;
} U64Variable;

typedef struct _u128_variable {
    __uint128_t value;
    __uint128_t* address;
} U128Variable;

typedef struct _f32_variable {
    float value;
    float* address;
} F32Variable;

typedef struct _bool_variable {
    bool value;
    bool* address;
} BoolVariable;

typedef struct _string_variable {
    char* value;
    char** address;
} StringVariable;


#endif //VARIABLE_H
