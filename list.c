#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node *allocateNode(float value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

List *allocateList() {
    List *list = malloc(sizeof(List));
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void freeList(List *list) {
    while(list->length > 0) {
        list = removeHeadList(list);
    }
    free(list);
}

List *insertHeadList(List *list, float value) {
    if(list == NULL) {
        list = allocateList();
    }
    Node *newNode = allocateNode(value);
    newNode->next = list->head;
    if(list->head != NULL) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }
    list->head = newNode;
    list->length++;

    return list;
}

List *insertTailList(List *list, float value) {
    if(list == NULL) {
        list = allocateList();
    }
    Node *newNode = allocateNode(value);
    newNode->prev = list->tail;
    if(list->tail != NULL) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
    list->length++;

    return list;
}

List *removeHeadList(List *list) {
    if(list == NULL || list->length == 0) {
        return NULL;
    }

    Node *tmp = list->head;
    list->head = tmp->next;
    if(list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(tmp);
    list->length--;

    return list;
}

List *removeTailList(List *list) {
    if(list == NULL || list->length == 0) {
        return NULL;
    }

    Node *tmp = list->tail;
    list->tail = tmp->prev;
    if(list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(tmp);
    list->length--;

    return list;
}

void printFullList(List *list) {
    if(list == NULL) {
        printf("List is undefined\n");
        return;
    }
    printf("List<%p>: Length->%d, Head->%p, Tail->%p\n=====================\n", list, list->length, list->head, list->tail);
    if(list->length != 0) {
        int i = 0;
        Node *It = list->head;
        while(It != NULL) {
            printf("Element %d<%p>: Value->%f, Next->%p, Prev->%p\n", i, It, It->value, It->next, It->prev);
            It = It->next;
            i++;
        }
    }
    putchar('\n');
}

void printList(List *list, int newline) {
    if(list == NULL) {
        printf("List is undefined\n");
        return;
    }
    putchar('[');
    Node *It = list->head;
    while(It != NULL) {
        printf("%f", It->value);
        if(It->next != NULL) {
            putchar(';');
        }
        It = It->next;
    }
    putchar(']');
    if(newline) {
        putchar('\n');
    }
}

/*I'm an excellent psy, and my fee is $10 per minute */