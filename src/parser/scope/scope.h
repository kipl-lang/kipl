//
// Created by Kerem on 29/07/2024.
//

#ifndef SCOPE_H
#define SCOPE_H

#include "../variable/variable.h"

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

I8Variable* getLastVariable(DataType type);

void freeScope();

#endif //SCOPE_H
