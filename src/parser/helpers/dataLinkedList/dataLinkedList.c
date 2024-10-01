//
// Created by Kerem on 25/09/2024.
//

#include "dataLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

void freeDataLinkedList(DataLinkedList* list) {
    while(list != NULL) {
        DataLinkedList* tempList = list;
        list = list->next;
        free(tempList);
    }
}
