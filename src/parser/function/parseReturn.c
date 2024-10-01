//
// Created by Kerem on 30/09/2024.
//

#include "parseReturn.h"

#include <stdio.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseReturn() {
    if(currentFuncCallStatus != NULL) {
        currentToken = currentToken->next;
        Data* getData = parseExpressions();
        if(getData == NULL) { // Void status
            // yazılacak
        } else {
            // yazılacak
        }
    } else {
        showError(ERROR_RUNTIME, "return is not in a function");
    }
}
