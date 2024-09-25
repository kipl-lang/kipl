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

Data* createData(DataType dataType, char* value);

Data* getDataFromVariable(char* name);

void freeData(Data* data);


#endif //DATA_H
