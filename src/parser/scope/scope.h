/**
The Kipl Programming Language

 File: parser/scope/scope.h

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#ifndef SCOPE_H
#define SCOPE_H

#include "../variable/variable.h"
#include "../expressions/data.h"

typedef struct _scope {
    // There are linked lists (var1 -> var2 -> var3 -> ... -> varn -> NULL)
    I8Variable* i8Variable;
    I16Variable* i16Variable;
    I32Variable* i32Variable;
    I64Variable* i64Variable;
    I128Variable* i128Variable;
    U8Variable* u8Variable;
    U16Variable* u16Variable;
    U32Variable* u32Variable;
    U64Variable* u64Variable;
    U128Variable* u128Variable;
    F32Variable* f32Variable;
    F64Variable* f64Variable;
    BoolVariable* boolVariable;
    StringVariable* stringVariable;

    struct _scope* parentScope;
} Scope;

void createScope();

bool isVariableInCurrentScope(const char* name);

bool isVariableInAllScope(const char* name);

bool dataTypeIsNumber(DataType type);

void assignToVariable(const char* varName, Data* data);

void freeScope();

void freeI8Variables();

void freeI16Variables();

void freeI32Variables();

void freeI64Variables();

void freeI128Variables();

void freeU8Variables();

void freeU16Variables();

void freeU32Variables();

void freeU64Variables();

void freeU128Variables();

void freeF32Variables();

void freeF64Variables();

void freeBoolVariables();

void freeStringVariables();

#endif //SCOPE_H
