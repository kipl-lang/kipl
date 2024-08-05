//
// Created by Kerem on 04/08/2024.
//

#include "Data.h"

#include <stdlib.h>

#include "../global.h"
#include "../variable/variable.h"


Data* createData(DataType dataType, char* value) {
    Data* data = (Data*) malloc(sizeof(Data)); // new data;
    data->dataType = dataType;
    data->value = value;
    return data;
}

Data* getDataFromVariable(char* name) {
    Scope* tempScope = currentToken;

    while(tempScope != NULL) {



        tempScope = tempScope->parentScope;
    }

    return NULL; // variable undefined
}