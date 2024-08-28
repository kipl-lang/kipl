//
// Created by Kerem on 25/08/2024.
//

#include "parseImport.h"

#include <stdio.h>
#include "../../lexer/lexer.h"

#include "../global.h"
#include "../error/error.h"
#include "../helpers/file/readFile.h"

void parseImport() {
    currentToken = currentToken->next;

    if(currentToken->type == TOKEN_STRING_LITERAL) {
        char fileName[128];
        sprintf(fileName, "%s.kipl", currentToken->value);

        char* string = readFile(fileName);       // kipl source code
        Token* firstToken =  scanner(string);    // lexer
        Token* lastToken = getLastTokenWithOutEOF(firstToken);

        if(lastToken != NULL) {
            lastToken->next = currentToken->next;
            currentToken->next = firstToken;
        }

        currentToken = currentToken->next;

    } else {
        showError(ERROR_SYNTAX, "Expected \"<file>\" after import");
    }
}

