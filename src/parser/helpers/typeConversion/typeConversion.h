//
// Created by Kerem on 05/08/2024.
//

#ifndef TYPECONVERSION_H
#define TYPECONVERSION_H

#include "stdint.h"
#include "stdbool.h"


char* boolToString(bool value);

char* i8ToString(int8_t value);

char* i16ToString(int16_t value);

char* i32ToString(int32_t value);

char* i64ToString(int64_t value);

char* i128ToString(__int128_t value);

char* u8ToString(uint8_t value);

char* u16ToString(uint16_t value);

char* u32ToString(int32_t value);

char* u64ToString(int64_t value);

char* u128ToString(__uint128_t value);


#endif //TYPECONVERSION_H
