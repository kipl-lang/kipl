//
// Created by Kerem on 04/08/2024.
//

#ifndef DATA_H
#define DATA_H

#include "../dataType.h"

typedef struct _data {
    DataType dataType;
    char* value;
} Data;


Data* getDataFromVariable(char* name);


#endif //DATA_H
