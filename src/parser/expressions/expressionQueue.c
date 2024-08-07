//
// Created by Kerem on 06/08/2024.
//

#include "expressionQueue.h"

#include <stdlib.h>

ExpressionQueue* createExpressionQueue() {
    ExpressionQueue* queue = (ExpressionQueue*) malloc(sizeof(ExpressionQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = 0;
    queue->elements = (ExpressionElement**) malloc(queue->capacity * sizeof(ExpressionElement*));
}

void enqueueExpression(ExpressionQueue* queue, ExpressionElement* element) {
    queue->elements = realloc(queue->elements, ++queue->capacity*sizeof(ExpressionElement*));

    if(queue->rear == -1)
        queue->rear++;
    queue->elements[++queue->rear] = element;
}