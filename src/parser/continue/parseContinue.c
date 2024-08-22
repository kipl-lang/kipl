//
// Created by Kerem on 22/08/2024.
//

#include "parseContinue.h"

#include "../parser/global.h"
#include "../parser/error/error.h"

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
