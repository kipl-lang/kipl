/**
 The Kipl Programming Language

 File: parser/global.h

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#ifndef GLOBAL_H
#define GLOBAL_H

#include "../token/token.h"
#include "../parser/scope/scope.h"
#include "for/for.h"
#include "function/function.h"
#include "if/trueBlock.h"
#include "switch/switch.h"

extern Token* currentToken;
extern Scope* currentScope;
extern unsigned int openCurlyBracket;
extern unsigned int openRoundBracket;
extern For* currentFor;
extern TrueBlock* currentTrueBlock;
extern Switch* currentSwitch;
extern Function* functions;
extern FuncCallStatus* currentFuncCallStatus;
#endif //GLOBAL_H