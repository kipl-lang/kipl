//
// Created by Kerem on 05/08/2024.
//

#include "toString.h"

#include <stdio.h>
#include <string.h>

char* int8_tToString(int8_t value) {
    char str[5];            // worst case -128 and NULL
    sprintf(str, "%d", value);
    return strdup(str);
}

char* int16_tToString(int16_t value) {
    char str[7];
    sprintf(str, "%d", value);
    return strdup(str);
}

char* int32_tToString(int32_t value) {
    char str[12];
    sprintf(str, "%d", value);
    return strdup(str);
}

char* int64_tToString(int64_t value) {
    char str[21];
    sprintf(str, "%lld", value);
    return strdup(str);
}

char* __int128_tToString(__int128_t value) {
    char str[41];
    sprintf(str, "%lld", (long long) value);
    return strdup(str);
}

char* uint8_tToString(uint8_t value) {
    char str[4];            // worst case 256 and NULL
    sprintf(str, "%u", value);
    return strdup(str);
}

char* uint16_tToString(uint16_t value) {
    char str[6];
    sprintf(str, "%u", value);
    return strdup(str);
}

char* uint32_tToString(uint32_t value) {
    char str[11];
    sprintf(str, "%u", value);
    return strdup(str);
}

char* uint64_tToString(uint64_t value) {
    char str[21];
    sprintf(str, "%llu", value);
    return strdup(str);
}

char* __uint128_tToString(__uint128_t value) {
    char str[40];
    sprintf(str, "%llu", (long long) value);
    return strdup(str);
}

char* floatToString(float value) {
    char str[50];
    sprintf(str, "%f", value);
    return strdup(str);
}

char* doubleToString(double value) {
    char str[50];
    sprintf(str, "%lf", value);
    return strdup(str);
}

char* boolToString(bool value) {
    if(value)
        return "true";

    return "false";
}