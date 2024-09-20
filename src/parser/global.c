/**
 The Kipl Programming Language

 File: parser/global.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include "global.h"

Token* currentToken = NULL;
Scope* currentScope = NULL;
unsigned int openCurlyBracket = 0;
unsigned int openRoundBracket = 0;
For* currentFor = NULL;
TrueBlock* currentTrueBlock = NULL;
Switch* currentSwitch = NULL;
Function* functions = NULL;
FuncCallStatus* funcCallStatus = NULL;