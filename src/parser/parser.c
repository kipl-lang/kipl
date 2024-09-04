/**
 The Kipl Programming Language

 File: parser/parser.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include "parser.h"

#include <stdio.h>

#include "global.h"
#include "break/parseBreak.h"
#include "commands/out/parseOut.h"
#include "continue/parseContinue.h"

#include "error/error.h"
#include "for/parseFor.h"
#include "identifier/parseIdentifier.h"
#include "if/parseIf.h"
#include "import/parseImport.h"
#include "variable/parseVariable.h"
#include "scope/scope.h"

void parser(Token* token) {
    currentToken = token;   // Current Token
    createScope();          // Current Scope

    while(currentToken->type != TOKEN_EOF) {
        if(currentToken->type == TOKEN_ERROR)
            showError(ERROR_SYNTAX, token->value);

        else if(currentToken->type == TOKEN_IMPORT)
            parseImport();

        else if(currentToken->type == TOKEN_VAR ||currentToken->type == TOKEN_CONST)
            parseVariable();

        else if(currentToken->type == TOKEN_IF)
            parseIf();

        else if(currentToken->type == TOKEN_FOR)
            parseFor();

        else if(currentToken->type == TOKEN_CONTINUE)
            parseContinue();

        else if(currentToken->type == TOKEN_BREAK)
            parseBreak();

        else if(currentToken->type == TOKEN_OUT)
            parseOut();

        else if(currentToken->type == TOKEN_IDENTIFIER)
            parseIdentifier();

        else if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
            createScope();
            openCurlyBracket++;
            currentToken = currentToken->next;
        }

        else if(currentToken->type == TOKEN_BRACKET_CURLY_RIGHT) {
            if(openCurlyBracket == 0)
                showError(ERROR_SYNTAX, "Curly brackets are not balanced");

            // for close control
            if(currentFor != NULL && openCurlyBracket == currentFor->lastBracketsNumber+1) {
                For* tempFor = currentFor;
                currentToken = currentFor->forToken;
                currentFor = currentFor->parentFor;
                freeFor(tempFor);
                openCurlyBracket--;
                freeScope();
            }
            // if close control
            else if(currentTrueBlock != NULL && openCurlyBracket == currentTrueBlock->lastBracketsNumber+1) {
                TrueBlock* tempTrueBlock = currentTrueBlock;
                currentToken = currentToken->next;
                currentTrueBlock = currentTrueBlock->parentTrueBlock;
                freeTrueBlock(tempTrueBlock);
                openCurlyBracket--;
                freeScope();

                unsigned int lastOpenCB = openCurlyBracket;

                while(currentToken->type == TOKEN_ELSE && currentToken->next->type == TOKEN_IF) {
                    currentToken = currentToken->next;
                    currentToken = currentToken->next;

                    while(currentToken->type != TOKEN_EOF && currentToken->type != TOKEN_BRACKET_CURLY_LEFT)
                        currentToken = currentToken->next;

                    if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
                        openCurlyBracket++;
                        currentToken = currentToken->next;
                        skipFalse(lastOpenCB);
                    } else {
                        showError(ERROR_SYNTAX, " expected '{' after else clause");
                    }
                }

                if(currentToken->type == TOKEN_ELSE) {
                    currentToken = currentToken->next;

                    if(currentToken->type == TOKEN_BRACKET_CURLY_LEFT) {
                        openCurlyBracket++;
                        currentToken = currentToken->next;
                        skipFalse(lastOpenCB);
                    } else {
                        showError(ERROR_SYNTAX, " expected '{' after else clause");
                    }
                }
            }
            // switch close control
            else if(currentSwitch != NULL && openCurlyBracket == currentSwitch->lastBracketsNumber+1) {
                Switch* tempSwitch = currentSwitch;
                currentToken = currentToken->next;
                currentSwitch = currentSwitch->parentSwitch;
                freeSwitch(tempSwitch);
                openCurlyBracket--;
                freeScope();
            }
            // other brackets status
            else {
                openCurlyBracket--;
                freeScope();
                currentToken = currentToken->next;
            }
        }

        else
            showError(ERROR_SYNTAX, "unkown syntax");
        //currentToken = currentToken->next;
    }

    if(openCurlyBracket != 0) // açılan curly brackets kapanmadıysa
        showError(ERROR_SYNTAX, "Curly brackets are not balanced");

    freeScope();
}
