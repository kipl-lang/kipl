//
// Created by Kerem on 05/08/2024.
//

#include "typeConversion.h"

#include <stdio.h>
#include <string.h>

char* boolToString(bool value) {
    if(value)
        return "true";

    return "false";
}

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

char* int128_tToString(int8_t value) {
    char str[21];
    sprintf(str, "%d", value);
    return strdup(str);
}