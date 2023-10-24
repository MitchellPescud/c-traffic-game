#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList* createList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    list->head = NULL;
    return list;
}

void insert(LinkedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertLast(LinkedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void removeLastElement(LinkedList *list) {
    Node *current = list->head;
    Node *prev = NULL;
    
    if (list->head == NULL) {
        return;
    }

    if (current->next == NULL) {
        free(current);
        list->head = NULL;
        return;
    }

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        list->head = NULL;
    }
}

void* getLastElement(LinkedList *list) {
    Node *current = list->head;
    if (current == NULL) {
        return NULL;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    return current->data;
}

void printList(LinkedList *list, void (*printFunction)(void *)) {
    Node *current = list->head;
    while (current != NULL) {
        printFunction(current->data);
        current = current->next;
    }
}


void freeList(LinkedList *list, void (*freeFunction)(void *)) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        freeFunction(temp->data);
        free(temp);
    }
    free(list);
}


void freedata(void *data) {
    free(data);
}