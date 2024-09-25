//
// Created by Kerem on 25/09/2024.
//

#ifndef DATALINKEDLIST_H
#define DATALINKEDLIST_H

#include "../../expressions/data.h"

typedef struct _data_linked_list {
    Data* data;
    struct _data_linked_list* next;
} DataLinkedList;

#endif //DATALINKEDLIST_H
