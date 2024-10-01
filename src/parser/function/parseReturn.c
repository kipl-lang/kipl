//
// Created by Kerem on 30/09/2024.
//

#include "parseReturn.h"

#include "../global.h"
#include "../error/error.h"

void parseReturn() {
    if(currentFuncCallStatus != NULL) {
        currentToken = currentToken->next;
    } else {
        showError(ERROR_RUNTIME, "return is not in a function");
    }
}
