//
// Created by Kerem on 04/09/2024.
//

#include "parseSwitch.h"

#include "../global.h"
#include "../expressions/parseExpressions.h"

void parseSwitch() {
    unsigned int lastOpenCurlyBracket = openCurlyBracket;
    currentToken = currentToken->next;
    Data* data = parseExpressions();
}
