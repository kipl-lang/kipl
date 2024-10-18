//
// Created by Kerem on 22/08/2024.
//

#include "parseBreak.h"

#include "../global.h"
#include "../error/error.h"
#include "stdlib.h"

void parseBreak() {
    if(currentFor != NULL) {
        currentToken = currentToken->next;

        while(currentToken->type != TOKEN_EOF) {
            if(currentToken->type ==TOKEN_BRACKET_CURLY_LEFT)
                openCurlyBracket++;
            else if(currentToken->type == TOKEN_BRACKET_CURLY_RIGHT) {
                openCurlyBracket--;
                if(currentFor->lastBracketsNumber == openCurlyBracket) {
                    For* tempFor = currentFor;
                    currentToken = currentToken->next;
                    currentFor = currentFor->parentFor;
                    freeFor(tempFor);
                    freeScope();
                    break;
                }
            }

            currentToken = currentToken->next;
        }
    } else {
        showError(ERROR_RUNTIME, "Break is not in a loop");
    }
}