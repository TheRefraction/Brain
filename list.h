#ifndef LIST_H
#define LIST_H

typedef struct STRUCT_NODE {
    float value;
    struct STRUCT_NODE *next;
    struct STRUCT_NODE *prev;
} Node;

typedef struct {
    int length;
    Node *head;
    Node *tail;
} List;

Node *allocateNode(float value);
List* allocateList();
void freeList(List* list);

List *insertHeadList(List *list, float value);
List *insertTailList(List *list, float value);
List *removeHeadList(List *list);
List *removeTailList(List *list);

void printFullList(List *list);
void printList(List *list, int newline);

// I am really happy to be here
#endif //LIST_H
