//
// Created by Kerem on 22/08/2024.
//

#include "parseContinue.h"
#include "../global.h"
#include "../error/error.h"
#include "stdlib.h"

void parseContinue() {
    if(currentFor != NULL) {
        For* tempFor = currentFor;
        currentToken = currentFor->forToken;
        currentFor = currentFor->parentFor;
        freeFor(tempFor);
        openCurlyBracket--;
        freeScope();
    } else {
        showError(ERROR_RUNTIME, "continue is not in a loop");
    }
}
