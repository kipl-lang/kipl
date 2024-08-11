//
// Created by Kerem on 11/08/2024.
//

#include "toBool.h"

#include <string.h>

bool stringToBool(char* value) {
    if(!strcmp(value, "false"))
        return false;

    return true;
}