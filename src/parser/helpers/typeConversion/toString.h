//
// Created by Kerem on 05/08/2024.
//

#ifndef TYPECONVERSION_H
#define TYPECONVERSION_H

#include "stdint.h"
#include "stdbool.h"


char* int8_tToString(int8_t value);

char* int16_tToString(int16_t value);

char* int32_tToString(int32_t value);

char* int64_tToString(int64_t value);

char* __int128_tToString(__int128_t value);

char* uint8_tToString(uint8_t value);

char* uint16_tToString(uint16_t value);

char* uint32_tToString(uint32_t value);

char* uint64_tToString(uint64_t value);

char* __uint128_tToString(__uint128_t value);

char* floatToString(float value);

char* doubleToString(double value);

char* boolToString(bool value);


#endif //TYPECONVERSION_H
