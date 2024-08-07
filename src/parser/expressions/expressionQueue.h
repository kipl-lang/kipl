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

ExpressionQueue* createExpressionQueue();

void enqueueExpression(ExpressionQueue* queue, ExpressionElement* element);

void dequeueExpression(ExpressionElement* element);

void freeExpressionQueue(ExpressionQueue* queue);

#endif //EXPRESSIONQUEUE_H
