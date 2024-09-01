//
// Created by Kerem on 01/09/2024.
//

#include "parseOut.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../global.h"
#include "../../error/error.h"
#include "../../expressions/parseExpressions.h"

void parseOut() {
    currentToken = currentToken->next;
    Data* data = parseExpressions();

    if(data != NULL) {
        printf(data->value);
        free(data);
    } else {
        showError(ERROR_SYNTAX, "Expected <value> print ");
    }
}
