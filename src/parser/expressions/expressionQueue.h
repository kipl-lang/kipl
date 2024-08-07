//
// Created by Kerem on 06/08/2024.
//

#ifndef EXPRESSIONQUEUE_H
#define EXPRESSIONQUEUE_H

#include "expressionElement.h"

typedef struct _expression_queue {
    int front;
    int rear;
    unsigned int capacity;
    ExpressionElement** elements;
} ExpressionQueue;

#endif //EXPRESSIONQUEUE_H
