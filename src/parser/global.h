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

extern Token* currentToken;
extern Scope* currentScope;
extern unsigned int openCurlyBracket;

#endif //GLOBAL_H
