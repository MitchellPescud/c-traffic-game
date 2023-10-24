#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*Structures*/
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

LinkedList* createList();
void insert(LinkedList *list, void *data);
void insertLast(LinkedList *list, void *data);
void removeLastElement(LinkedList *list);
void* getLastElement(LinkedList *list);
void printList(LinkedList *list, void (*printFunction)(void *));
void freeList(LinkedList *list, void (*freeFunction)(void *));
void freedata(void *data);

#endif