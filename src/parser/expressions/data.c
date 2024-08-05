//
// Created by Kerem on 04/08/2024.
//

#include "data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../global.h"
#include "../helpers/typeConversion/typeConversion.h"
#include "../variable/variable.h"


Data* createData(DataType dataType, char* value) {
    Data* data = (Data*) malloc(sizeof(Data)); // new data;
    data->dataType = dataType;
    data->value = value;
    return data;
}

Data* getDataFromVariable(char* name) {
    Scope* tempScope = currentScope;

    while(tempScope != NULL) {

        I8Variable* tempI8Variable = tempScope->i8Variable;
        while(tempI8Variable != NULL) {
            if(!strcmp(name, tempI8Variable->name)) {
                char* str = int8_tToString(tempI8Variable->value);
                return createData(TYPE_I8, str);
            }
            tempI8Variable = tempI8Variable->next;
        }

        tempScope = tempScope->parentScope;
    }

    return NULL; // variable undefined
}

void freeData(Data* data) {
    free(data->value);
    free(data);
}