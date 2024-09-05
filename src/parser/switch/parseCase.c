//
// Created by Kerem on 05/09/2024.
//

#include "parseCase.h"

#include "../global.h"
#include "../error/error.h"
#include "../expressions/parseExpressions.h"

void parseCase() {
    if(currentSwitch != NULL) {
        currentToken = currentToken->next;
        Data* data = parseExpressions();

        if(data != NULL) {
            if(data->dataType == currentSwitch->data->dataType) {

            } else {
                showError(ERROR_RUNTIME,
                    "The type of the switch expression does not match the type of the case value.");
            }
        } else {
            showError(ERROR_SYNTAX, "Expected <value> after case");
        }
    } else {
        showError(ERROR_SYNTAX, "Case is not in switch");
    }
}
