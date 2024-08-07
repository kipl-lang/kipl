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

void dequeueExpression(ExpressionQueue* queue) {
    if(queue->front == -1 && queue->front != queue->rear+1) {
        free(queue->elements[queue->front]);
        queue->elements[queue->front] = NULL;
        queue->front++;
    }
}

void freeQueueExpression(ExpressionQueue* queue) {
    free(queue->elements);
    free(queue);
}