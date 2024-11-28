#ifndef LIST_H
#define LIST_H

#include <stddef.h>

/**
 * definition of a new structure "Node" who is a link list of value
 */
typedef struct STRUCT_NODE {
    float value;
    struct STRUCT_NODE *next;
    struct STRUCT_NODE *prev;
} Node;

/**
 * definition of the length the head and the tail of the link list of Nodes
 */
typedef struct {
    int length;
    Node *head;
    Node *tail;
} List;

/**
 * allocate memory for a new node
 * @param value
 * @return
 */
Node *allocateNode(float value);
/**
 * allocate memory for a new list
 * @return
 */
List* allocateList();

/**
 * create a new list
 * @param length
 * @param value
 * @return
 */
List *createList(size_t length, float value);

/**
 * free the list
 * @param list
 */
void freeList(List* list);

/**
 * insert a value in head of the list
 * @param list
 * @param value
 * @return
 */
List *insertHeadList(List *list, float value);

/**
 * insert a value in tail of the list
 * @param list
 * @param value
 * @return
 */
List *insertTailList(List *list, float value);

/**
 * remove the head of a list
 * @param list
 * @return
 */
List *removeHeadList(List *list);

/**
 * remove the tail of a list
 * @param list
 * @return
 */
List *removeTailList(List *list);

/**
 * print a list (with his tail, his head and his lenght) and all the element of the list with the address of the next one and the prev one.
 * @param list
 */
void printFullList(List *list);

/**
 * print a list with only the value (example:[1;2])
 * @param list
 * @param newline print a lign after the result
 */
void printList(const List *list, int newline);

// I am really happy to be here
#endif //LIST_H
