#ifndef LIST_H
#define LIST_H

#include <stddef.h>

/**
 * definition of a new structure "Node"
 */
typedef struct STRUCT_NODE {
    float value;
    struct STRUCT_NODE *next;
    struct STRUCT_NODE *prev;
} Node;

/**
 * definition of the lenght the head and the tail of the link list of NOde
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
 * free the 
 * @param list
 */
void freeList(List* list);

/**
 *
 * @param list
 * @param value
 * @return
 */
List *insertHeadList(List *list, float value);

/**
 *
 * @param list
 * @param value
 * @return
 */
List *insertTailList(List *list, float value);

/**
 *
 * @param list
 * @return
 */
List *removeHeadList(List *list);

/**
 *
 * @param list
 * @return
 */
List *removeTailList(List *list);

/**
 *
 * @param list
 */
void printFullList(List *list);

/**
 *
 * @param list
 * @param newline
 */
void printList(List *list, int newline);

// I am really happy to be here
#endif //LIST_H
