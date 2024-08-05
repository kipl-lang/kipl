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
    char str[4];
    sprintf(str, "%d", value);
    return strdup(str);
}